<h1 align="center">:rotating_light: Ordenação de Arquivos Grandes de Registros </h1>
<p align="center">
 Com o objetivo de ordenar arquivos com grande quantidade de <b><i>bytes</i></b> utilizando uma quantidade limitada de memoria principal, utilizamos a técnica de particionamento. Onde cada partição é ordenada pelo algoritmo de <b><i>quicksort</i></b> e terá um buffer de entrada auxiliar, iremos então utilizar intercalação por <b><i>k-vias</i></b> para preencher o buffer de sáida.
 </p>
<p align="center">
<img src="https://img.shields.io/github/repo-size/jhonatancunha/ed2_k-way_merge" alt="">
<img src="https://img.shields.io/github/license/jhonatancunha/ed2_k-way_merge" alt="">
<img src="https://img.shields.io/github/last-commit/jhonatancunha/ed2_k-way_merge" alt="">
</p>
<br>


### :red_circle: Como utilizar

```bash
# Clone este repositório
$ git clone https://github.com/jhonatancunha/ed2_k-way_merge

# Acesse a pasta do projeto no terminal/cmd
$ cd ed2_k-way_merge

# Execute o makefile (windows)
$ mingw32-make

# Execute o makefile (linux)
$ make

# Por fim inicie o executavel
$ main quantidadeDeRegistros maximoDeMemoriaDisponivel porçãoMemoriaBufferSaida

```

### :mag: Exemplo
```bash
#Executei passando os seguintes argumentos
$ main 256000 8388608 2
```

Obtemos as seguintes informações como saida do algoritmo.<br />
<img src="img/exemplo.PNG" alt="">


### Autores
---

<a href="https://github.com/jhonatancunha">
 <img style="border-radius: 50%;" src="https://avatars0.githubusercontent.com/u/52831621?s=460&u=2b0cfdafeb7756176ded82c41738e773e92762b8&v=4" width="100px;" alt=""/>
<br />
 <sub><b>Jhonatan Cunha</b></sub></a> <a href="https://github.com/jhonatancunha" title="Repositorio Jhonatan">🚀</a>

[![Gmail Badge](https://img.shields.io/badge/-jhonatancunha@alunos.utfpr.edu.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:jhonatancunha@alunos.utfpr.edu.br)](mailto:jhonatancunha@alunos.utfpr.edu.br)
<br />

<a href="https://github.com/JessePires">
 <img style="border-radius: 50%;" src="https://avatars0.githubusercontent.com/u/20424496?s=460&u=87f2870ff153ab88402d6246cb3347a46ae33fe9&v=4" width="100px;" alt=""/>
<br />
 <sub><b>Jessé Pires</b></sub></a> <a href="https://github.com/JessePires" title="Repositorio Jessé">🚀</a>

[![Gmail Badge](https://img.shields.io/badge/-jessepires@alunos.utfpr.edu.br-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:jessepires@alunos.utfpr.edu.br)](mailto:jessepires@alunos.utfpr.edu.br)

