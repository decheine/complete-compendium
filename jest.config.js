module.exports = {
    preset: 'ts-jest',
    testEnvironment: `node`,
    setupFilesAfterEnv: ["<rootDir>/setup-test-env.js"],
    globals: {
      'ts-jest': {
        tsconfig: 'tsconfig.json',
      },
    },
  }