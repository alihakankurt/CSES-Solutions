import dataclasses
import html
import os
import shutil

import bs4
import requests

CSES_PROBLEMSET_URL: str = "https://cses.fi/problemset"
CSES_IGNORE: list[str] = ["General"]
CSES_PROBLEM_URL: str = "https://cses.fi{href}"
SOLUTIONS_PATH: str = "./"
SITE_GENERATOR_PATH: str = "./site-generator"
SITE_ROOT_PATH: str = "./docs"


@dataclasses.dataclass
class Problem:
    name: str
    url: str
    solved: bool


@dataclasses.dataclass
class Topic:
    name: str
    problems: list[Problem]


def fetch_problem_data() -> list[Topic]:
    response = requests.get(CSES_PROBLEMSET_URL)
    soup = bs4.BeautifulSoup(response.text, "html.parser")

    content = soup.find("div", class_="content")
    if not content:
        print("Root content could not be found!")
        return []

    topics: list[Topic] = []
    for topic_header in content.find_all("h2"):
        topic_name: str = topic_header.getText().strip()
        if topic_name in CSES_IGNORE:
            continue

        tasklist = topic_header.find_next("ul", class_="task-list")
        if not tasklist:
            print(f"Could not be able to find problems for {topic_name}")
            continue

        problems: list[Problem] = []
        for item in tasklist.find_all("li", class_="task"):
            link = item.find("a")
            if not link:
                print(f"Could not be able to find the problem for {topic_name}")
                continue

            problem_name: str = link.getText().strip()
            solved = os.path.exists(f"{SOLUTIONS_PATH}/{topic_name}/{problem_name}.cpp")

            if problem_href := link.get("href"):
                problems.append(
                    Problem(
                        problem_name, CSES_PROBLEM_URL.format(href=problem_href), solved
                    )
                )

        topics.append(Topic(topic_name, problems))

    return topics


def prepare_site_generation(topics: list[Topic]) -> str:
    if not os.path.isdir(SITE_ROOT_PATH):
        os.mkdir(SITE_ROOT_PATH)

    for topic in topics:
        topic_path = f"{SITE_ROOT_PATH}/{topic.name}"
        if not os.path.isdir(topic_path):
            os.mkdir(topic_path)
        for problem in topic.problems:
            problem_path = f"{SITE_ROOT_PATH}/{topic.name}/{problem.name}"
            if not os.path.isdir(problem_path):
                os.mkdir(problem_path)

    shutil.copy(f"{SITE_GENERATOR_PATH}/style.css", SITE_ROOT_PATH)
    shutil.copy(f"{SITE_GENERATOR_PATH}/script.js", SITE_ROOT_PATH)
    shutil.copy(f"{SITE_GENERATOR_PATH}/highlight.js", SITE_ROOT_PATH)

    with open(f"{SITE_GENERATOR_PATH}/layout.html") as file:
        return file.read()


def generate_home_page(layout: str, topics: list[Topic]) -> None:
    topic_template = """
                <a href="/CSES-Solutions/{name}" class="card-link">
                    <div class="card">
                        <div class="card-header">
                            <h5 class="card-title">{name}</h5>
                        </div>
                        <div class="card-stats">
                            <div class="stat-total">
                                <div class="stat-title">Total</div>
                                <div>{total_count}</div>
                            </div>
                            <div class="stat-solved">
                                <div class="stat-title">Solved</div>
                                <div>{solved_count}</div>
                            </div>
                        </div>
                        <div class="card-progress">
                            <div class="card-progress-percentage">%{completion}</div>
                            <div class="card-progress-bar">
                                <div
                                    class="card-progress-fill"
                                    style="width: {completion}%"
                                ></div>
                            </div>
                        </div>
                    </div>
                </a>
    """

    template = """
            <div class="container">
                <div class="grid">
            {topic_cards}
                </div>
            </div>
"""

    def render_topic(topic: Topic) -> str:
        total_count = len(topic.problems)
        solved_count = len(list(filter(lambda problem: problem.solved, topic.problems)))
        completion = round(solved_count / total_count * 100, 2)
        return topic_template.format(
            name=topic.name,
            total_count=total_count,
            solved_count=solved_count,
            completion=completion,
        )

    topic_cards = "".join(map(render_topic, topics))
    content = template.format(topic_cards=topic_cards)

    document = layout.format(head="", title="CSES Solutions", content=content)
    with open(f"{SITE_ROOT_PATH}/index.html", "w") as file:
        _ = file.write(document)


def generate_topic_page(layout: str, topic: Topic) -> None:
    problem_template = """
                    <a href="/CSES-Solutions/{topic_name}/{name}">
                        <div class="problem-card">
                            <span class="problem-card-title">
                                {name}
                            </span>
                            <span
                                class="problem-card-status {state}"
                                title="{state}"
                            ></span>
                        </div>
                    </a>
    """

    template = """
            <div class="container">
                <h3 class="topic-title">{name}</h3>
                <div class="problem-grid">
            {problem_cards}
                </div>
            </div>
"""

    def render_problem(problem: Problem) -> str:
        return problem_template.format(
            topic_name=topic.name,
            name=problem.name,
            state="solved" if problem.solved else "unsolved",
        )

    problem_cards = "".join(map(render_problem, topic.problems))
    content = template.format(name=topic.name, problem_cards=problem_cards)

    document = layout.format(head="", title=topic.name, content=content)
    with open(f"{SITE_ROOT_PATH}/{topic.name}/index.html", "w") as file:
        _ = file.write(document)


def generate_problem_page(layout: str, topic: Topic, problem: Problem) -> None:
    head = """
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.11.1/highlight.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlightjs-line-numbers.js/2.9.0/highlightjs-line-numbers.min.js"></script>
    <script src="/CSES-Solutions/highlight.js"></script>
"""

    template = """
            <div class="container">
                <h3 class="problem-title">
                    <a href="{url}">{topic_name} / {name}</a>
                </h3>
                <div class="problem-code-block">
                    <pre><code class="language-cpp">{code}
                    </code></pre>
                </div>
            </div>
"""

    if problem.solved:
        with open(f"{SOLUTIONS_PATH}/{topic.name}/{problem.name}.cpp") as file:
            code = file.read()
    else:
        code = "// This problem is currently unsolved."

    code = html.escape(code)
    content = template.format(
        url=problem.url, topic_name=topic.name, name=problem.name, code=code
    )

    document = layout.format(head=head, title=problem.name, content=content)
    with open(f"{SITE_ROOT_PATH}/{topic.name}/{problem.name}/index.html", "w") as file:
        _ = file.write(document)


if __name__ == "__main__":
    data = fetch_problem_data()

    layout = prepare_site_generation(data)
    generate_home_page(layout, data)
    for topic in data:
        generate_topic_page(layout, topic)
        for problem in topic.problems:
            generate_problem_page(layout, topic, problem)
