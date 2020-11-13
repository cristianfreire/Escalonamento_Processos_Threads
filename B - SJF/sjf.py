from operator import itemgetter

def TempoEspera(processos):
    tempo_servico=[0]*len(processos)
    tempo_espera=[0]*len(processos)
    for x in range(1, len(processos)):
        tempo_servico[x]=(tempo_servico[x-1]+processos[x-1][2])
        tempo_espera[x]=tempo_servico[x]-processos[x][1]
        if (tempo_espera[x]<0):
            tempo_espera[x]=0
    return tempo_espera

def TempoResposta(processos):
    tempo_resposta=[0]*len(processos)
    tempo_espera=TempoEspera(processos)
    for x in range(len(processos)):
        tempo_resposta[x]=processos[x][2]+tempo_espera[x]
    return tempo_resposta

def ExecucaoMedia(processos):
    tempo_resposta=sum(TempoResposta(processos)) 
    return (tempo_resposta/len(processos))

def EsperaMedia(processos):
    tempo_espera = sum(TempoEspera(processos))
    return (tempo_espera / len(processos))

def SJF(processos):
    processos.sort(key=itemgetter(2))
    return processos

quant=0
while(True):
    # print("SJF:\n")
    processos=[]
    N=int(input(""))
    if(N==0):
        break
    for x in range(1, N + 1):
        pid=f"P{x}"
        X=int(input(""))
        Y=int(input(""))
        processos.append([pid, X, Y])
    # print("\n")
    
    tempo_espera=TempoEspera(processos)
    tempo_resposta=TempoResposta(processos)
    execucao_media=ExecucaoMedia(processos)
    espera_media=EsperaMedia(processos)
    
    # print(processos)

    quant+=1
    print(f"\nTeste {quant}")
    print(f"Tempo médio de execução: {execucao_media}s")
    print(f"Tempo Médio de Espera: {espera_media}s")
    final = ''
    for proc in range(len(processos)):
        final += processos[proc][0] + ' '
        #print(f"{processos[proc][0]}")
    print(final);
