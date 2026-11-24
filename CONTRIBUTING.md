# Contributing to Mini-RT

Thank you for your interest in contributing to Mini-RT!

This document describes the development workflow, coding standards, and contribution guidelines used by the Mini-RT team.

## 1. Development Workflow

The `main` branch is the central integration branch.

All new features, fixes, and significant changes must be developed in dedicated branches.

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

## 2. Pull Requests and Code Review

All changes must be submitted through Pull Requests targeting `main`.

Each Pull Request must include:

- A clear description of the changes.
- The reason for the changes.
- The tests performed.
- Any relevant technical considerations.

Every Pull Request must be reviewed and approved by the other developer before being merged.

The author of a Pull Request cannot approve their own changes.

Significant architectural, mathematical, or memory-management changes should receive particular attention during code review.

## 3. Coding Standards

All contributions should follow the project's coding conventions.

- Follow the applicable 42 coding standards whenever possible.
- Norminette is used as a style reference, but is not a mandatory merge requirement.
- Keep functions focused and readable.
- Use meaningful variable and function names.
- Avoid unnecessary code duplication.
- Handle memory allocation and deallocation carefully.
- Maintain consistency with the existing architecture.

## 4. Build and Compilation

Every Pull Request must satisfy the following requirements:

- The project must compile successfully using the project's Makefile.
- All compilation flags defined in the Makefile must be respected.
- No compilation errors are allowed.

The Makefile is the reference for the project's compilation requirements.

## 5. Testing Requirements

Every new feature must include relevant tests.

- Tests must cover the expected behavior of the feature.
- Edge cases should be considered whenever applicable.
- Bug fixes should include a test reproducing the original issue whenever possible.
- Existing tests must continue to pass.
- Tests must be reproducible and documented when necessary.

Testing should cover mathematical operations, ray intersections, scene parsing, rendering, and memory management as the project evolves.

## 6. Memory Safety

Memory safety is a mandatory requirement.

- No new memory leaks are allowed.
- No invalid memory accesses are allowed.
- No memory-related errors may be introduced.
- Valgrind or an equivalent memory analysis tool must be used when applicable.

Contributors are responsible for ensuring that their changes do not introduce memory management issues.

## 7. Commit Messages

Commit messages should be concise, descriptive, and reflect the purpose of the change.

Examples:

- `feat: add sphere intersection`
- `fix: correct ray direction calculation`
- `refactor: simplify vector operations`
- `docs: update rendering documentation`

## 8. Project Philosophy

Mini-RT is developed collaboratively.

Contributions should prioritize:

- Mathematical correctness.
- Code quality and maintainability.
- Rendering accuracy.
- Memory safety.
- Clear separation of responsibilities.

Technical decisions affecting the overall architecture should be discussed between both developers before implementation.

## 9. Branch Management

Once a Pull Request has been reviewed, approved, and successfully merged into `main`, the associated feature or fix branch should be deleted.

Branches should not be kept after their changes have been integrated unless there is a specific reason to retain them.

The `main` branch remains the central integration branch.

Thank you for helping improve Mini-RT!
