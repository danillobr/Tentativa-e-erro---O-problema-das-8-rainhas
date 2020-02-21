#include <bits/stdc++.h>
#define N 8

int tabuleiro[N][N];

void criaTabuleiro(int tabuleiro[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

bool verificaPosicao(int x, int y){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if( ((i == x) || (j == y) ||(abs(i-x) == abs(j-y))) && tabuleiro[i][j] == 1  )
              return false;
        }
    }
    return true;
}


int feito=0;
void inserirRainha(int x, int y){
    if(y == N){
        feito++;
        return;
    }
    for(int i=0; x+i < N; i++){
        if(!feito && verificaPosicao(x+i, y)){
            tabuleiro[x+i][y] = 1;
            inserirRainha(0, y+1);
            if(!feito) tabuleiro[x+i][y] = 0;
        }
    }
}

void imprimirTabuleiro(){
    if(!feito) return;
    printf("\n\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
}

void oitoRainhas(){
    criaTabuleiro(tabuleiro);
    inserirRainha(0, 0);
    imprimirTabuleiro();
    if(!feito) printf("\nNao eh possivel");
    feito = 0;
}

int main(){
    oitoRainhas();
    return 0;
}