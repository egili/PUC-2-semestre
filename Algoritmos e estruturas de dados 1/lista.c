#include <stdio.h>

typedef struct {
    unsigned int idAutor;
    unsigned int codNacionalidade;
    unsigned int anoNascimento;
} Autor;

typedef struct {
    unsigned int idEditora;
    unsigned int codPais;
    unsigned int anoFundacao;
} Editora;

typedef struct {
    unsigned int idCategoria;
    unsigned int codArea;
} Categoria;

typedef struct {
    unsigned int idLivro;
    unsigned int idAutor;
    unsigned int idEditora;
    unsigned int idCategoria;
    unsigned int anoPublicacao;
    unsigned int numPaginas;
} Livro;

typedef struct {
    unsigned int idExemplar;
    unsigned int idLivro;
    unsigned short int codEstado; // (1=novo,2=bom,3=regular,4=ruim)
} Exemplar;

typedef struct {
    unsigned int idAluno;
    unsigned int codCurso;
    unsigned int anoIngresso;
} PessoaAluno;

typedef struct {
    unsigned int idProfessor;
    unsigned int codDepartamento;
    unsigned int anoContratacao;
} PessoaProfessor;

typedef struct {
    unsigned int idFuncionario;
    unsigned int codCargo;
    unsigned int anoAdmissao;
} Funcionario;

typedef struct {
    unsigned int idEmprestimo;
    unsigned int idExemplar;
    unsigned int idPessoa; 
    unsigned int tipoPessoa; // 0 - aluno, 1 - PessoaProfessor
    unsigned int anoEmprestimo;
    unsigned int anoDevolucao; // 0 se ainda nao tiver devolvido
} Emprestimo;

typedef struct {
    unsigned int idReserva;
    unsigned int idLivro;
    unsigned int idPessoa;
    unsigned int tipoPessoa;
    unsigned int anoReserva;
} Reserva;

typedef struct {
    unsigned int idSala;
    unsigned int capacidade;
    unsigned int codLocalizacao;
} SalaEstudo;

typedef struct {
    unsigned int idReservaSala;
    unsigned int idSala;
    unsigned int idPessoa;
    unsigned int tipoPessoa;
    unsigned int anoReserva;
    unsigned int qtdPessoas;
} ReservaSala;

typedef struct {
    unsigned int idMulta;
    unsigned int idEmprestimo;
    float valor;
    unsigned short int pago; // 0 nao, 1 sim
} Multa;

typedef struct {
    unsigned int idEvento;
    unsigned int codTipoEvento;
    unsigned int anoEvento;
} Evento;

typedef struct {
    unsigned int idParticipacao;
    unsigned int idEvento;
    unsigned int idPessoa;
    unsigned int tipoPessoa;
} ParticipacaoEvento;

typedef struct {
    unsigned int idDoacao;
    unsigned int idLivro;
    unsigned int codDoador; // 0 - externo, >0 - idPessoa
    unsigned int anoDoacao;
} Doacao;

typedef struct {
    unsigned int idRevisao;
    unsigned int idExemplar;
    unsigned int idFuncionario;
    unsigned int anoRevisao;
} RevisaoExemplar;

typedef struct {
    unsigned int idSugestao;
    unsigned int idPessoa; // quem sugeriu
    unsigned int tipoPessoa;
    unsigned int codTemaLivro;
    unsigned int anoSugestao;
} SugestaoCompra;

typedef struct {
    unsigned int idRecomendacao;
    unsigned int idProfessor;
    unsigned int idLivro;
    unsigned int anoRecomendacao;
} RecomendacaoLeitura;

// ex 1
int alunosSemEmprestimoNoAno(PessoaAluno* alunos, int alunosSize, Emprestimo* emprestimos, int emprestimosSize, unsigned int ano) {
    int qtdAlunosQueNaoFizeramEmprestimosNoAno = 0;
    
    for(int i = 0; i < alunosSize; i++) {
        int booleanFezEmprestimo = 0;
        for(int j = 0; j < emprestimosSize; j++) {
            if(emprestimos[j].tipoPessoa == 0) {
                if(emprestimos[j].idPessoa == alunos[i].idAluno && emprestimos[j].anoEmprestimo == ano) {
                    booleanFezEmprestimo = 1;
                    break;
                } 
            }
        }
        if(booleanFezEmprestimo == 0) {
            qtdAlunosQueNaoFizeramEmprestimosNoAno += 1;
        }
    }
    return qtdAlunosQueNaoFizeramEmprestimosNoAno;
}

// ex 2
int livrosSemExemplarBom(Livro* livros, int livrosSize, Exemplar* exemplares, int exemplaresSize, Categoria* categorias, int categoriasSize, int idCategoria) {
    int qtdLivrosSemExemplarBom = 0;
    
    for(int i = 0; i < livrosSize; i++) {
        if(idCategoria == 0 || livros[i].idCategoria == idCategoria) {
            int temExemplarBom = 0;
            for(int j = 0; j < exemplaresSize; j++) {
                
                if(livros[i].idLivro == exemplares[j].idLivro && (exemplares[j].codEstado == 1 || exemplares[j].codEstado == 2)) {
                    temExemplarBom = 1;
                    break;
                }
            }
            if(temExemplarBom == 0) {
                qtdLivrosSemExemplarBom += 1;
            }
        }
        
    }
    return qtdLivrosSemExemplarBom;
}

// ex3
int professoresEmTodosEventos(PessoaProfessor* professores, int professoresSize, Evento* eventos, int eventosSize, ParticipacaoEvento* participacoesEventos, int participacoesEventosSize, unsigned int ano) {
    
    int qtdProfessoresTodosEventos = 0;
    int totalEventosAno = 0;
  
    for (int i = 0; i < professoresSize; i++) {
        int eventosParticipados = 0;
        
        for (int j = 0; j < eventosSize; j++) {
            if (eventos[j].anoEvento == ano) {
                totalEventosAno++;
                int participou = 0;
                for (int k = 0; k < participacoesEventosSize; k++) {
                    if (participacoesEventos[k].tipoPessoa == 1 &&
                        participacoesEventos[k].idPessoa == professores[i].idProfessor &&
                        participacoesEventos[k].idEvento == eventos[j].idEvento) {
                        participou = 1;
                        break;
                    }
                }
                if (participou) {
                    eventosParticipados++;
                }
            }
        }
        if (eventosParticipados == totalEventosAno) {
            qtdProfessoresTodosEventos++;
        }
    }
    
    return qtdProfessoresTodosEventos;
}

// ex 4
int reservasNaoAtendidas(Reserva* reservas, int reservasSize, Livro* livros, int livrosSize, Exemplar* exemplares, int exemplaresSize, Emprestimo* emprestimos, int emprestimosSize) {

    int qtdReservasNaoAtendidas = 0;
    
    
}

// ex 5 
int salasSempreLotadasAno(SalaEstudo* salasEstudo, int salasEstudoSize, ReservaSala* reservasSala, int reservasSalaSize, unsigned int ano, PessoaAluno* alunos, int alunosSize, PessoaProfessor* professores, int professoresSize) {
    return 0;
}

// ex 6 
int exemplaresRevisadosPorVarios(RevisaoExemplar* revisaoesExemplares, int revisaoesExemplaresSize, Exemplar* exemplares, int exemplaresSize, Funcionario* funcionarios, int funcionariosSize, Livro* livros, int livrosSize, Categoria* categorias, int categoriasSize) {
    return 0;    
}

// ex 7 
int usuariosSemMultasComDevolucao(PessoaAluno* alunos, int alunosSize, PessoaProfessor* professores, int professoresSize, Emprestimo* emprestimos, int emprestimosSize, Multa* multas, int multasSize, Doacao* doacoes, int doacoesSize) {
    return 0;
}

// ex 8 
int sugestoesAtendidasPorAquisição(SugestaoCompra* sugestoesCompra, int sugestoesCompraSize, Livro* livros, int livrosSize, Doacao* doacoes, int doacoesSize, Editora* editoras, int editorasSize, Autor* autores, int autoresSize, Categoria* categorias, int categoriasSize) {
    return 0;
}

// ex 9 
int professoresRecomendamEditora(PessoaProfessor* professores, int professoresSize, RecomendacaoLeitura* recomendacoesLeitura, int recomendacoesLeituraSize, Livro* livros, int livrosSize, Editora* editoras, int editorasSize, Autor* autores, ParticipacaoEvento* participacoesEventos, int participacoesEventosSize, Doacao* doacoes, int doacoesSize) {
    return 0;
}

// ex 10
int relatorioAcervoCompleto(Autor* autores, int autoresSize,Editora* editoras, int editorasSize, Categoria* categorias, int categoriasSize, Livro* livros, int livrosSize, Exemplar* exemplares, int exemplaresSize, PessoaAluno* alunos, int alunosSize, PessoaProfessor* professores, int professoresSize, Funcionario* funcionarios, int funcionariosSize, Emprestimo* emprestimos, int emprestimosSize, Reserva* reservas, int reservasSize, SalaEstudo* salasEstudo, int salasEstudoSize, ReservaSala* reservasSala, int reservasSalaSize, Multa* multas, int multasSize, Evento* eventos, int eventosSize, ParticipacaoEvento* participacoesEventos, int participacoesEventosSize, Doacao* doacoes, int doacoesSize, RevisaoExemplar* revisaoesExemplares, int revisaoesExemplaresSize, SugestaoCompra* sugestoesCompra, int sugestoesCompraSize, RecomendacaoLeitura* recomendacoesLeitura, int recomendacoesLeituraSize) {
    return 0;
}

int main() {
    
    Autor autores[3] = { {1, 10, 1950}, {2, 20, 1910}, {3, 10, 1940} };
    
    Editora editoras[2] = { {1, 1, 1955}, {2, 2, 1920} };
    
    Categoria categorias[2] = { {1, 100}, {2, 200} };
    
    Livro livros[4] = { {1, 1, 1, 1, 1899, 300}, {2, 2, 2, 2, 1949, 250}, {3, 3, 1, 1, 1977, 150}, {4, 1, 2, 1, 2005, 400} };
        
    Exemplar exemplares[5] = { {1,1,1}, {2,1,2}, {3,2,2}, {4,3,1}, {5,4,1} }; 
    
    PessoaAluno alunos[3] = { {1, 101, 2020}, {2, 102, 2021}, {3, 103, 2022} };
    
    PessoaProfessor professores[2] = { {1, 301, 2010}, {2, 302, 2015} }; 
    
    Funcionario funcionarios[2] = { {1, 401, 2000}, {2, 402, 2005} };
    
    Emprestimo emprestimos[5] = { {1,1,1,0,2024,2024}, {2,2,2,0,2024,0}, {3,3,3,0,2023,2023}, {4,4,1,1,2024,2024}, {5,5,4,0,2024,0} }; 
    
    Reserva reservas[3] = { {1,1,1,0,2024}, {2,2,3,0,2024}, {3,4,2,1,2024} };
    
    SalaEstudo salas[2] = { {1,4,1}, {2,6,2} }; 
    
    ReservaSala reservasSala[2] = { {1,1,1,0,2024,4}, {2,2,2,1,2024,6} };
    
    Multa multas[2] = { {1,1,5.0,0}, {2,3,10.0,1} };
    
    Evento eventos[2] = { {1, 1, 2024}, {2, 2, 2024} };
    
    ParticipacaoEvento participacoes[3] = { {1,1,1,1}, {2,1,2,1}, {3,2,1,0} }; 
    
    Doacao doacoes[2] = { {1,2,0,2023}, {2,3,0,2024} };
    
    RevisaoExemplar revisoes[3] = { {1,1,1,2023}, {2,1,2,2024}, {3,4,1,2024} }; 
    
    SugestaoCompra sugestoes[2] = { {1,1,0,10,2023}, {2,2,1,20,2024} };
    
    RecomendacaoLeitura recomendacoes[2] = { {1,1,1,2024}, {2,2,3,2024} };
    
    printf("qtd alunos sem emprestimno %d", alunosSemEmprestimoNoAno(alunos, 3, emprestimos, 5, 2023));
    
    printf("\nqtd livro sem exemplar bom %d", livrosSemExemplarBom(livros, 4, exemplares, 5, categorias, 2, 0));

    printf("\n qtd professores em todos os eventos %d", professoresEmTodosEventos(professores, 2, eventos, 2, participacoes, 3, 2024));
}