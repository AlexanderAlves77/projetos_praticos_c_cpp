# Contributing to Game Engineering na Prática

Obrigado pelo interesse em contribuir com o projeto **Game Engineering na Prática**.

Este projeto possui um objetivo educacional e arquitetural específico: construir progressivamente uma Game Engine e um jogo real utilizando C++, sem introduzir complexidade antes que exista uma necessidade concreta.

Por isso, contribuições devem respeitar não apenas o funcionamento do código, mas também a filosofia de evolução do projeto.

---

# Filosofia

A principal regra é:

> **Problema antes da abstração.**

Evite introduzir sistemas, padrões ou dependências apenas porque são comuns em outras engines.

Uma contribuição que proponha uma nova abstração deverá conseguir responder:

1. Qual problema atual ela resolve?
2. Onde esse problema pode ser observado?
3. Qual é a solução mais simples?
4. Por que a solução atual deixou de ser suficiente?
5. Quais alternativas foram consideradas?
6. Quais custos a nova abstração adiciona?
7. Como podemos validar que ela realmente melhorou o projeto?

---

# Princípios

Contribuições devem priorizar:

* clareza;
* simplicidade;
* legibilidade;
* baixo acoplamento;
* alta coesão;
* responsabilidades claras;
* comportamento testável;
* evolução incremental;
* documentação;
* performance baseada em evidências;
* segurança quando aplicável.

Evite:

* abstrações prematuras;
* generalização sem caso de uso;
* dependências desnecessárias;
* grandes refatorações sem justificativa;
* otimizações sem profiling;
* padrões aplicados apenas pelo nome;
* classes sem responsabilidade clara.

---

# Ambiente inicial

A configuração inicial do projeto utiliza:

```text
C++20
Visual Studio Community 2022
MSVC
Windows x64
SFML 3.1.0
Git
```

A stack poderá evoluir durante o desenvolvimento.

Antes de adicionar uma nova dependência externa, abra uma discussão ou descreva claramente na Pull Request:

* problema;
* necessidade;
* alternativas;
* benefício;
* impacto;
* licença;
* manutenção;
* riscos.

---

# Estrutura do projeto

A estrutura deve crescer progressivamente.

Não crie antecipadamente diretórios ou módulos apenas porque eles aparecem no roadmap futuro.

Por exemplo, a existência futura de:

```text
Audio/
Physics/
Scene/
SaveLoad/
Tools/
UI/
```

não significa que essas pastas devam existir antes de possuírem implementação real.

> **Pastas representam responsabilidades existentes, não intenções futuras.**

---

# Código

## Idioma

Identificadores de código devem ser escritos em inglês.

Exemplo:

```cpp
class Player
{
private:
    int health;
    int energy;
};
```

Evite:

```cpp
class Jogador
{
private:
    int vida;
    int energia;
};
```

Documentação textual pode ser escrita em português do Brasil.

---

# Headers e Source Files

Quando apropriado, utilizar separação:

```text
Player.h
Player.cpp
```

Evite colocar implementações extensas em headers sem necessidade técnica.

---

# Naming

Utilize nomes que expressem intenção.

Prefira:

```cpp
playerHealth
remainingEnergy
loadTexture()
calculateDistance()
```

Evite:

```cpp
x
temp
data2
thing
manager2
```

quando o contexto não tornar o significado evidente.

---

# Magic Strings

Evite espalhar strings que representem conceitos fechados do domínio.

Quando apropriado, considere tipos mais seguros, como:

```cpp
enum class PlayerState
{
    Idle,
    Walking,
    Working,
    Sleeping
};
```

Não transforme toda string em enum automaticamente.

A escolha deve ser conceitualmente justificada.

---

# Classes

Toda nova classe deve responder:

> **Por que esta classe precisa existir?**

Evite classes que apenas transferem comportamento de um arquivo para outro sem criar responsabilidade clara.

---

# Design Patterns

Design Patterns são ferramentas.

Não são requisitos arquiteturais.

Uma contribuição utilizando Strategy, Observer, Factory, State, Command ou qualquer outro padrão deverá demonstrar o problema que tornou o padrão útil.

Evite pattern-driven development.

---

# SOLID

Os princípios SOLID poderão orientar decisões arquiteturais, mas não devem ser tratados como regras absolutas.

O objetivo é produzir software sustentável, e não maximizar a quantidade de abstrações.

---

# Performance

Não aceite uma otimização apenas porque ela parece teoricamente mais rápida.

Sempre que possível:

```text
Measure
   ↓
Identify Bottleneck
   ↓
Hypothesize
   ↓
Optimize
   ↓
Measure Again
```

Contribuições de performance relevantes devem incluir evidências, benchmarks ou profiling quando aplicável.

---

# Testes

À medida que a infraestrutura de testes for construída, mudanças em regras de negócio ou sistemas determinísticos deverão incluir testes quando apropriado.

Possíveis áreas:

* Math;
* Physics;
* Collision;
* Inventory;
* Economy;
* Farming;
* Save/Load;
* Engine;
* Integration.

Testes devem ser:

* determinísticos quando possível;
* independentes;
* legíveis;
* rápidos;
* focados em comportamento.

---

# Commits

Utilize commits pequenos e semanticamente coerentes.

O projeto prefere Conventional Commits.

Exemplos:

```text
feat: add application lifecycle
fix: resolve runtime library mismatch
refactor: extract window responsibility
test: add inventory tests
docs: update engine roadmap
perf: reduce redundant texture loading
build: configure release dependencies
ci: add automated test workflow
```

Evite commits como:

```text
changes
updates
fix stuff
final
final2
working now
various fixes
```

---

# Branches

Quando necessário, utilize branches descritivas.

Exemplos:

```text
feat/application-lifecycle
feat/input-system
fix/runtime-library
refactor/resource-loading
test/inventory
docs/engine-architecture
```

---

# Pull Requests

Uma Pull Request deve explicar claramente:

## What

O que foi alterado?

## Why

Por que essa mudança é necessária?

## How

Como o problema foi resolvido?

## Validation

Como a alteração foi validada?

## Tests

Quais testes foram executados ou adicionados?

## Trade-offs

Existem custos, limitações ou decisões relevantes?

---

# Bugs

Um bom bug report deve conter, quando possível:

* descrição;
* comportamento esperado;
* comportamento observado;
* passos para reprodução;
* ambiente;
* configuração Debug/Release;
* arquitetura x64/x86;
* mensagens de erro;
* logs;
* screenshots quando úteis;
* frequência;
* impacto.

Não publique secrets, tokens, credenciais ou informações sensíveis nos logs.

---

# Documentação

Mudanças relevantes poderão exigir atualização de:

```text
README.md
CHANGELOG.md
ROADMAP.md
CONTRIBUTING.md
```

Uma funcionalidade não deve ser considerada completamente integrada quando sua documentação essencial estiver desatualizada.

---

# Segurança

Nunca faça commit de:

* passwords;
* tokens;
* API keys;
* private keys;
* credentials;
* secrets;
* arquivos contendo dados sensíveis.

Caso uma credencial seja acidentalmente publicada, considere-a comprometida e faça sua rotação.

---

# Assets

Antes de contribuir com:

* sprites;
* imagens;
* fontes;
* músicas;
* sound effects;
* modelos;
* outros recursos externos;

confirme que sua licença permite utilização e redistribuição no projeto.

Documente attribution quando exigido.

---

# Pull Request Checklist

Antes de enviar uma contribuição:

* [ ] O projeto compila;
* [ ] A configuração utilizada está documentada;
* [ ] Não foram introduzidos warnings desnecessários;
* [ ] O código segue as convenções existentes;
* [ ] A mudança resolve um problema concreto;
* [ ] Não foi adicionada abstração prematura;
* [ ] Testes relevantes passam;
* [ ] Novos testes foram adicionados quando necessários;
* [ ] README foi atualizado quando necessário;
* [ ] CHANGELOG foi atualizado quando necessário;
* [ ] ROADMAP foi atualizado quando necessário;
* [ ] Nenhum secret foi incluído;
* [ ] Assets possuem licença compatível;
* [ ] O commit possui mensagem clara.

---

# Código de colaboração

Discussões técnicas devem permanecer:

* respeitosas;
* objetivas;
* fundamentadas;
* abertas a alternativas.

Discordâncias arquiteturais são normais e podem ser extremamente valiosas.

A pergunta principal não deve ser:

> "Qual solução parece mais sofisticada?"

Mas:

> **"Qual solução resolve melhor o problema atual sem comprometer desnecessariamente a evolução do projeto?"**

---

## Autor e mantenedor

**Alexander Alves**
*C++ Game Developer | Game Engineering | Software Engineering*

GitHub: **AlexanderAlves77**
