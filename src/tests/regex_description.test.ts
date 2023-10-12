

import getRegexDescription from "../components/regex_description"

const ALL_MONSTERS = require( "../data/ALL_MONSTERS.json")
const aarakath_data = ALL_MONSTERS[0]
// console.log("aarakath:", aarakath_data)
const target_fullbody:string = aarakath_data["monster_data"]["fullBody"]
// const target_fullbody:string = "some text"

// console.log("Target fullbody:")

// console.log(target_fullbody)

// Text tested against:
const text_test:string = "Some text <p class=\"f\"> other text </p>"

test("Testing if Regex Description function returns a value", () => {
    expect(getRegexDescription("aarakath", target_fullbody)).not.toHaveLength(0);
});

test("Regex description with text_test", () => {
    expect(getRegexDescription("aarakath", text_test)).not.toHaveLength(0);
});

// test("Single backslash slash", () => {
//     expect(
//         "some text \\ some other text".match(/(\\)/)![1]
//         ).not.toHaveLength(0);
// });

// test("Single backslash quote", () => {
//     expect(
//         "some text\"some other text".match(/(\")/)![1]
//         ).not.toHaveLength(0);
// });

// test("Quote AND backslash", () => {
//     expect(
//         "some text\\\"some other text".match(/(\\\")/)![1]
//         ).not.toHaveLength(0);
// });

