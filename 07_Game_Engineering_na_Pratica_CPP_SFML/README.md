# 🎮 Game Engineering na Prática — C++ & SFML

> Construindo, do zero, uma Game Engine própria e um jogo 2D completo utilizando C++, SFML e princípios profissionais de Engenharia de Software.

![C++](https://img.shields.io/badge/C%2B%2B-20-blue?logo=cplusplus)
![SFML](https://img.shields.io/badge/SFML-3.1.0-green)
![Platform](https://img.shields.io/badge/Platform-Windows%20x64-lightgrey)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-purple)
![Status](https://img.shields.io/badge/Status-In%20Development-orange)
![License](https://img.shields.io/badge/License-TBD-lightgrey)

---

## 📖 Sobre o projeto

**Game Engineering na Prática** é um projeto educacional e prático de desenvolvimento de games em C++, criado para acompanhar a construção progressiva de uma **Game Engine própria** e de um **jogo 2D completo**.

O projeto começa propositalmente pequeno.

Sem uma arquitetura gigante pronta.

Sem dezenas de sistemas criados antecipadamente.

Sem abstrações cuja necessidade ainda não apareceu.

A evolução seguirá um princípio fundamental:

> **Problema → solução simples → uso real → limitação → análise → refatoração → evolução arquitetural.**

Cada sistema deverá surgir porque existe um problema concreto que justifique sua existência.

O objetivo não é apenas desenvolver um jogo que funcione.

O objetivo é estudar e aplicar **Game Engineering** durante todo o ciclo de desenvolvimento.

---

## 🎯 Objetivos

Este projeto será utilizado para estudar e aplicar progressivamente:

* Programação;
* C++ moderno;
* Engenharia de Software;
* Game Development;
* Game Engine Development;
* Arquitetura de Games;
* Matemática para Games;
* Física;
* Rendering;
* Input;
* Audio;
* Resource Management;
* Gameplay Systems;
* Game AI;
* Persistência;
* Automated Testing;
* Tools Engineering;
* Telemetria;
* Data Engineering;
* Machine Learning;
* Inteligência Artificial;
* Performance Engineering;
* Segurança;
* DevOps;
* CI/CD;
* QA;
* Playtesting;
* Release Engineering;
* Packaging;
* Distribuição;
* Produção e pós-lançamento.

---

## 🕹️ O jogo

A Game Engine será desenvolvida junto de um jogo 2D real.

A direção inicial combina elementos de:

* Farming;
* Management;
* Exploration;
* Economy;
* NPCs;
* Inventory;
* Resources;
* Progression;
* Interaction;
* Maps;
* Time Cycles;
* Persistence.

O jogo funcionará como consumidor real da Engine.

Isso significa que decisões arquiteturais não serão tomadas apenas porque determinado padrão é popular.

A Engine deverá evoluir em resposta às necessidades concretas do jogo.

---

## 🧠 Filosofia de desenvolvimento

### Primeiro o problema

Nenhuma abstração importante deverá existir antes de compreendermos o problema que ela pretende resolver.

Não começaremos o projeto criando antecipadamente:

```text
SceneManager
ResourceManager
AudioManager
EventBus
ServiceLocator
EntityManager
ComponentManager
SystemManager
```

Esses componentes poderão surgir futuramente.

Mas somente quando o crescimento do software justificar sua existência.

### Arquitetura evolutiva

O projeto poderá começar praticamente assim:

```text
CppGameEngine/
└── main.cpp
```

E evoluir progressivamente para algo semelhante a:

```text
CppGameEngine/
│
├── Audio/
├── Core/
├── Engine/
├── Farm/
├── Game/
├── Input/
├── Math/
├── Particles/
├── Physics/
├── Resources/
├── Scene/
├── SaveLoad/
├── Tools/
├── UI/
└── main.cpp
```

Essa estrutura representa um possível **destino arquitetural**, não a estrutura inicial obrigatória.

Cada módulo será criado quando sua responsabilidade surgir naturalmente.

---

## 🧰 Stack inicial

| Tecnologia                   | Utilização                  |
| ---------------------------- | --------------------------- |
| C++                          | Linguagem principal         |
| C++20                        | Standard inicial            |
| SFML 3.1.0                   | Multimedia/Game Development |
| Visual Studio Community 2022 | IDE inicial                 |
| MSVC                         | Compiler Toolchain          |
| Windows x64                  | Plataforma inicial          |
| Git                          | Versionamento               |
| GitHub                       | Repositório                 |
| MSBuild / Visual Studio      | Build inicial               |

Outras tecnologias serão adicionadas somente quando o projeto realmente precisar delas.

---

## 🔨 Build System

No início, o projeto será configurado manualmente através do Visual Studio.

Isso inclui compreender:

```text
Additional Include Directories
Additional Library Directories
Additional Dependencies
Preprocessor Definitions
Runtime Library
Debug / Release
x64 / x86
DLLs
```

O objetivo é compreender primeiro o funcionamento de compilação, linking e dependências.

Ferramentas como **CMake** serão introduzidas posteriormente, quando existir um problema real de build que justifique sua adoção.

---

## 🧱 Game Engine

A Engine será construída progressivamente.

Entre os sistemas que poderão surgir durante a evolução estão:

* Application Lifecycle;
* Game Loop;
* Window;
* Time;
* Input;
* Keyboard;
* Mouse;
* Rendering;
* Resources;
* Textures;
* Fonts;
* Audio;
* Animation;
* Scene Management;
* Camera;
* Collision;
* Physics;
* Particles;
* UI;
* Save/Load;
* Configuration;
* Logging;
* Diagnostics;
* Debugging;
* Profiling;
* Serialization;
* Data;
* AI;
* Testing Infrastructure.

Nenhum desses sistemas será criado apenas para preencher uma arquitetura.

---

## 🧪 Game Automation Framework

O projeto também desenvolverá progressivamente uma infraestrutura própria de testes automatizados voltada para games.

Uma possível evolução futura:

```text
Tests/
│
├── Core/
├── Engine/
├── Game/
├── Math/
├── Physics/
├── Integration/
├── Fakes/
├── Mocks/
├── Fixtures/
├── Assertions/
├── Utilities/
└── TestRunner/
```

Entre os possíveis alvos de testes estarão:

* matemática;
* regras de gameplay;
* inventário;
* economia;
* farming;
* física determinística;
* colisões;
* serialização;
* Save/Load;
* integração entre sistemas.

---

## 🤖 Game AI, Machine Learning e IA

O projeto tratará essas áreas separadamente.

### Game AI

Inicialmente:

* Finite State Machines;
* Pathfinding;
* A*;
* Behavior Trees;
* Utility AI.

### Machine Learning

Somente depois que existirem dados e problemas adequados:

* Datasets;
* Features;
* Classification;
* Regression;
* Clustering;
* Prediction;
* Player Behavior;
* Difficulty Analysis;
* Balance Analysis.

### Generative AI

Poderá ser estudada posteriormente para:

* ferramentas de desenvolvimento;
* prototipação;
* geração assistida de conteúdo;
* experimentação de diálogos;
* análise de dados.

IA será introduzida quando resolver problemas reais, não apenas para adicionar tecnologia ao projeto.

---

## 📊 Performance

O princípio de Performance Engineering será:

```text
Measure
   ↓
Identify
   ↓
Hypothesize
   ↓
Optimize
   ↓
Measure Again
```

Serão estudados progressivamente:

* CPU;
* GPU;
* Memory;
* Allocations;
* Cache;
* Data Locality;
* Frame Time;
* FPS;
* Draw Calls;
* Resource Loading;
* Profiling;
* Benchmarking.

---

## 🔐 Segurança

À medida que surgirem arquivos, saves, APIs, backend, dados ou serviços externos, também serão estudados:

* Input Validation;
* Trust Boundaries;
* Save Integrity;
* Secrets;
* Authentication;
* Authorization;
* Dependency Security;
* Supply Chain;
* External Content;
* Mods;
* Cheating.

---

## 🚀 Do desenvolvimento à produção

O projeto não será considerado concluído simplesmente quando o jogo estiver executando.

A jornada também pretende abordar:

```text
Development
    ↓
Testing
    ↓
Profiling
    ↓
QA
    ↓
Playtesting
    ↓
Vertical Slice
    ↓
Polish
    ↓
Release Build
    ↓
Packaging
    ↓
Distribution
    ↓
Publication
    ↓
Production
    ↓
Post-launch
```

---

## 📚 Série Game Engineering na Prática

O desenvolvimento deste projeto acompanha a série:

**Game Engineering na Prática — Do Zero ao Jogo Comercial com C++ e SFML**

Os artigos são publicados no **Medium**.

A série acompanha a evolução do projeto desde os primeiros fundamentos de programação até Game Engine Development, QA, performance, release e produção.

---

## 🌱 Status atual

O projeto encontra-se em sua fase inicial.

A estratégia é começar com a menor estrutura possível e permitir que a arquitetura cresça junto das necessidades reais.

Consulte o [ROADMAP.md](ROADMAP.md) para acompanhar a evolução planejada.

Consulte o [CHANGELOG.md](CHANGELOG.md) para acompanhar as mudanças realizadas.

Consulte o [CONTRIBUTING.md](CONTRIBUTING.md) antes de contribuir.

---

## 📄 Licença

A licença definitiva do projeto ainda será definida.

Até que um arquivo `LICENSE` seja adicionado ao repositório, nenhum direito de reutilização deve ser presumido.

---

> **Game Engineering não é apenas fazer o jogo funcionar. É compreender como construí-lo, testá-lo, evoluí-lo, otimizá-lo e prepará-lo para chegar às mãos dos jogadores.**

---

## 👨‍💻 Autor

### Alexander Alves

**C++ Game Developer | Game Engineering | Software Engineering**

Desenvolvedor focado na construção e estudo de games, Game Engines, arquitetura de software e sistemas utilizando C++.

GitHub: **AlexanderAlves77**