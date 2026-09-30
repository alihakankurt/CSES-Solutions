document.addEventListener("DOMContentLoaded", function () {
    const body = document.body;
    const select = document.getElementById("theme-select");

    const themes = Array.from(select.options).map((option) => option.value);

    const savedTheme = localStorage.getItem("theme") ?? themes[0];
    if (themes.includes(savedTheme)) {
        body.classList.remove(...themes);
        body.classList.add(savedTheme);
        select.value = savedTheme;
    }

    select.addEventListener("change", function () {
        body.classList.remove(...themes);
        body.classList.add(this.value);
        localStorage.setItem("theme", this.value);
    });
});
