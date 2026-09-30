document.addEventListener("DOMContentLoaded", function () {
    const cpp = hljs.getLanguage("cpp");

    const customCpp = Object.assign({}, cpp, {
        keywords: Object.assign({}, cpp.keywords, {
            type:
                (cpp.keywords.type || "") +
                " i8 i16 i32 i64 isize u8 u16 u32 u64 usize f32 f64",
        }),
    });

    hljs.registerLanguage("cpp-custom", function () {
        return customCpp;
    });

    code = document.querySelector("pre code.language-cpp")
    code.classList.remove("language-cpp");
    code.classList.add("language-cpp-custom");

    hljs.highlightElement(code);
    hljs.initLineNumbersOnLoad();
});
