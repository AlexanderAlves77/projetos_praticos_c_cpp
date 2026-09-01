# Changelog

Todas as mudanças relevantes deste projeto serão documentadas neste arquivo.

O formato é inspirado em **Keep a Changelog**, com adaptações adequadas à evolução educacional e experimental do projeto.

O projeto pretende adotar versionamento formal quando sua maturidade justificar releases versionadas.

---

## [Unreleased]

### Added

* Definição inicial do projeto **Game Engineering na Prática**;
* Definição da proposta de construção progressiva de uma Game Engine própria;
* Definição do jogo 2D como consumidor real da Engine;
* Definição inicial de C++20;
* Definição inicial de SFML 3.1.0;
* Definição do Visual Studio Community 2022 como IDE inicial;
* Definição do MSVC como toolchain inicial;
* Definição de Windows x64 como plataforma inicial;
* Definição da estratégia de configuração manual do ambiente antes da introdução de CMake;
* Definição da estratégia de arquitetura evolutiva;
* Definição da estratégia de Game Automation Framework próprio e progressivo;
* Definição da futura exploração de Game AI, dados, Machine Learning e IA;
* Definição da estratégia de Performance Engineering baseada em medição;
* Definição da evolução futura para DevOps, CI/CD, QA, Release Engineering e produção;
* Adicionado `README.md`;
* Adicionado `ROADMAP.md`;
* Adicionado `CONTRIBUTING.md`;
* Adicionado `CHANGELOG.md`.

- Added the initial C++ project;
- Added the first `main.cpp`;
- Added the first executable console application;
- Configured the project for C++20;
- Configured the initial x64 development target.

- Added initial player state variables for health, coins, and level.
- Added state updates during program execution.
- Added console output for initial and current player state.

- Added typed player state data.
- Added player name, speed, alive state, and grade.
- Added examples using `int`, `float`, `bool`, `char`, and `std::string`.

- Added immutable game rule constants.
- Added maximum player health and inventory slot limits.
- Added default player speed configuration.
- Added separation between game rules and mutable player state.

- Added arithmetic operations for player state updates.
- Added compound assignment examples for health, coins, and experience.
- Added critical damage calculation using multiplication.
- Added integer division and remainder examples for experience progression.

- Added compound gameplay expressions.
- Added damage calculation using arithmetic precedence and parentheses.
- Added intermediate values for clearer expression evaluation.
- Added floating-point health percentage calculation.
- Added manual validation examples for expression results.


---

## Tipos de mudanças

As alterações poderão ser agrupadas nas seguintes categorias:

### Added

Novas funcionalidades, sistemas, módulos, ferramentas ou documentação.

### Changed

Mudanças relevantes em funcionalidades existentes.

### Deprecated

Funcionalidades mantidas temporariamente, mas planejadas para remoção.

### Removed

Funcionalidades removidas.

### Fixed

Correções de bugs e problemas técnicos.

### Security

Correções ou melhorias relacionadas à segurança.

### Performance

Melhorias comprovadas de performance.

### Refactored

Refatorações relevantes que alterem a estrutura interna sem necessariamente alterar o comportamento externo.

### Tests

Mudanças relevantes na infraestrutura ou cobertura de testes.

---

## Política de atualização

O `CHANGELOG.md` deverá ser atualizado quando houver mudanças relevantes para compreender a evolução do projeto.

Pequenas alterações internas sem impacto arquitetural, funcional ou educacional não precisam necessariamente gerar uma entrada individual.

A intenção deste arquivo é permitir que seja possível acompanhar a transformação do projeto:

```text
main.cpp
    ↓
C++ Application
    ↓
Game Application
    ↓
Game Engine
    ↓
Complete Game
    ↓
Production Software
```

---

## Autor

**Alexander Alves**
*C++ Game Developer | Game Engineering | Software Engineering*
