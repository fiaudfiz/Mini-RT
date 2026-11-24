# Contributing to Mini-RT

Thank you for your interest in contributing to Mini-RT!

This document describes the development workflow, coding standards, and contribution guidelines used by the Mini-RT team.

## 1. Development Workflow

The `main` branch is the central integration branch.

All new features, fixes, and significant changes should be developed in dedicated branches.

Recommended branch naming:

- `feat/` — New features
- `fix/` — Bug fixes
- `refactor/` — Code restructuring
- `docs/` — Documentation changes
- `test/` — Tests

Examples:
- `feat/sphere-intersection`
- `fix/memory-leak`
- `refactor/ray-calculation`

Branches should be created from the latest `main` branch.

## 2. Pull Requests

Changes should be submitted through Pull Requests targeting `main`.

Each Pull Request should include:

- A clear description of the changes.
- The reason for the changes.
- The tests performed.
- Any relevant technical considerations.

Code reviews are flexible and depend on the scope and complexity of the changes.

Significant architectural, mathematical, or memory-management changes should receive particular attention from the other developer.

## 3. Coding Standards

All contributions must follow the project's coding conventions.

- Follow the applicable 42 coding standards.
- Keep functions focused and readable.
- Use meaningful variable and function names.
- Avoid unnecessary code duplication.
- Handle memory allocation and deallocation carefully.
- Keep the code consistent with the existing architecture.

## 4. Testing

Before submitting a Pull Request:

- Ensure the project compiles successfully.
- Test the modified functionality.
- Check for memory leaks and invalid memory accesses.
- Ensure existing functionality has not been broken.

## 5. Commit Messages

Commit messages should be concise, descriptive, and reflect the purpose of the change.

Examples:

- `feat: add sphere intersection`
- `fix: correct ray direction calculation`
- `refactor: simplify vector operations`
- `docs: update rendering documentation`

## 6. Project Philosophy

Mini-RT is developed collaboratively.

Contributions should prioritize:

- Mathematical correctness.
- Code quality and maintainability.
- Rendering accuracy.
- Memory safety.
- Clear separation of responsibilities.

Technical decisions affecting the overall architecture should be discussed between both developers before implementation.

Thank you for helping improve Mini-RT!
