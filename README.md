# CPP07 • Templates — README ✨

> A gentle, practical guide to **C++98 templates** with clear explanations, pitfalls, and copy‑pasteable examples for **ex00–ex02**.
> **Note on `.tpp`** 🔧: Treat it as an **extension of the header**—put template definitions in `X.tpp` and `#include "X.tpp"` at the **bottom** of `X.hpp`. Do **not** compile `.tpp` separately.

---

## 🧭 Quick Primer (CPP‑07)

**Template** → write code **once**, use it for **many types**. The compiler generates the concrete code when you use it.

**Two common kinds:**

* **Function templates** (e.g., generic `swap`, `min`, `max`)
* **Class/struct templates** (e.g., generic `Pair<T, U>`, `Vector<T>`, or your `Array<T>`)

---

## 📚 Table of Contents

1. [What is a Template?](#-what-is-a-template)
2. [Function Templates](#-function-templates)
3. [Class Templates](#-class-templates)
4. [“Array template” vs “class template”](#-array-template-vs-class-template)
5. [Use‑case Cheatsheet](#-usecase-cheatsheet)
6. [Common Pitfalls (C++98‑friendly)](#-common-pitfalls-c98)

---

## 🧠 What is a Template?

A **template** is a compile‑time recipe the compiler uses to **generate real code** for each concrete type you use. Instead of rewriting the same algorithm/class for `int`, `double`, `std::string`, you write it **once** with a **type parameter** (often `T`).

* Resolved **at compile time** (no runtime overhead).
* Compiler **instantiates** a new function/class for each unique set of template arguments it encounters.
* Enables **generic algorithms** and **generic data structures**.

> **42 Rule**: Template **definitions** must be visible at the point of instantiation → keep them in headers (or headers that include a `.tpp`).

---

## 🛠️ Function Templates

A **function template** is a function whose parameter (and sometimes return) types depend on template parameters.

```cpp
// whatever.hpp (ex00)
#pragma once

template <typename T>
void swap(T &a, T &b) {
    T tmp = a; a = b; b = tmp;
}

// Return the second argument when equal (matches subject)
template <typename T>
T const & min(T const & a, T const & b) { return (b <= a) ? b : a; }

template <typename T>
T const & max(T const & a, T const & b) { return (a < b) ? b : a; }
```

**Use when:**

* The **same algorithm** works across many types (transforms, printing, utilities like `min/max/swap`).
* Logic is type‑agnostic, only requiring certain operations (e.g., `<`, `<=`).

> ✅ Yes: for **each standalone function template**, put `template <typename T>` **above that function**. The template parameter list applies only to the **next declaration**.

---

## 🧱 Class Templates

A **class template** is a class whose members/fields/behavior depend on template parameters (usually `T`). Perfect for **generic containers** and **type‑agnostic wrappers**.

```cpp
// Box<T> — minimal example

template <typename T>
class Box {
private:
    T value;
public:
    Box(): value() {}
    explicit Box(T const & v): value(v) {}
    T const & get() const { return value; }
    void set(T const & v) { value = v; }
};

// Defining a member outside the class body
// (note: repeat the template line and qualify with Box<T>::)
template <typename T>
void Box<T>::set(T const & v) { value = v; }
```

**Use when:**

* You build **data structures** (arrays, lists, stacks) or wrappers that must hold **any** type.
* You want compile‑time type safety **and** generic code.

### 🆚 Normal class vs. class template

**Normal class (single concrete type)**

```cpp
class Clerk {
public:
    void writeDocuments();
};

void Clerk::writeDocuments() { /* ... */ }
```

* `Clerk` is **one** concrete type.
* `Clerk::writeDocuments()` defines the member for that one type.

**Class template (many generated types)**

```cpp
template <typename T>
class Box {
public:
    void set(T const & v);
};

template <typename T>
void Box<T>::set(T const & v) { /* ... */ }
```

* `Box` is a **template** (a recipe).
* `Box<int>`, `Box<std::string>` are **different generated types**.
* You must repeat `template <typename T>` and qualify with `Box<T>::` when defining out‑of‑class members.

---

## 🧮 “Array template” vs “class template”

* An **array template** is simply a **specific class template** that implements array‑like behavior for an element type `T`.
* In `ex02`, **`Array<T>`** is your array template: allocate with `new[]`, provide `operator[]`, throw on OOB, expose `size()`.

> Every “array template” **is** a class template; it’s just a specific container use case.

---

## 🗺️ Use‑case Cheatsheet

| Need                                      | Use                             | Why                                                             |
| ----------------------------------------- | ------------------------------- | --------------------------------------------------------------- |
| One algorithm for many types              | **Function template**           | Avoid duplicate functions for `int`, `double`, `std::string`, … |
| Reusable container/wrapper for any type   | **Class template**              | Store and manage values of arbitrary type `T`                   |
| Iterate over any array & apply a callable | **Function template** (`iter`)  | Third param can itself be a function template instance          |
| Type‑agnostic dynamic array               | **Class template** (`Array<T>`) | Manual `new[]`/`delete[]`, `operator[]`, OOB checks, `size()`   |

---

## ⚠️ Common Pitfalls (C++98‑friendly) <a id="-common-pitfalls-c98"></a>

* **Definitions must be visible**: Put template **definitions** in headers, or in a `.tpp` that’s included by the header.
* **Comparison requirements**: `min`/`max` require `<` and `<=` for `T`.
* **`toupper`/`tolower`**: Cast to `unsigned char` first to avoid UB with negative `char`.
* **Exception safety (ex02)**: Simple deep copy is fine; strong guarantee not required.
* **Stay C++98**: No `auto`, `nullptr`, range‑for, etc.

---