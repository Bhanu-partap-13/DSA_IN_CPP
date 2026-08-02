import { describe, expect, it } from "vitest";
import contentIndex from "./data/contentIndex.json";

describe("App", () => {
  it("has generated content index sections", () => {
    expect(contentIndex).toHaveProperty("generatedAt");
    expect(contentIndex).toHaveProperty("days");
    expect(contentIndex).toHaveProperty("topics");
    expect(contentIndex).toHaveProperty("leetcode");
    expect(contentIndex).toHaveProperty("problems");
  });
});
