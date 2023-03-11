 <section>   
    <h1>📢 AEDS: Caminho Guloso</h1>   
    <p>
        Criado em Março de 2023, o projeto <strong>Caminho Guloso</strong> foi desenvolvido em virtude de atender as demandas do curso de Algoritimo e Estrutura de Dados, ministrado pelo professor <a href="https://www.linkedin.com/in/michelpiressilva/?originalSubdomain=br">Michel Pires Da Silva</a> no Centro Federal de Educação Tecnológica de Minas Gerais (<a href="https://www.divinopolis.cefetmg.br/">CEFET-MG</a>).
    </p>
</section>
<section>
    <h2>🛠 Problemática</h2>
    <p>
        Atualmente, no universo da programação, saber trabalhar com o conceito de caminhamento em matrizes tem se tornado algo cada vez mais indispensável. Em função disso, este algoritimo apresenta um método para percorrer matrizes de forma gulosa, ou seja, optando por um dado caminho e não mais olhando para trás ou para decisões já tomadas. Assim sendo, o objetivo do algoritimo porposto neste projeto é caminhar por um conjunto de matrizes fornecidas como entrada e encontrar, para cada, o maior valor final do caminho seguido. Além disso, pretende-se com isso:
    </p>
    <ul>
        <li>Revisar os conceitos de programação básica com matrizes;</li>
        <li>Começar um cenário de questionamentos para identificar se realmente a implementação realizada é a forma otimizada;</li>
        <li>Iniciar uma busca para uma boa estruturação de código.</li>
    </ul>
</section>
<section>
    <h2>🚧 Regras</h2>
    <p>
        Ao se tratar das matrizes, o algoritimo deve enumerá-las, de forma a deixa-las organizadas para o processamento. Após isso, partindo da primeira matriz, iniciar o percurso do caminho guloso do primeiro elemento até que alcance o ultimo. Feito isso, verificar se existem mais matrizes e caso haja realizar o mesmo processamento para todas.
    </p>
    <p>
        Ademais, no que se refere aos arquivos de entrada, deve-se seguir algumas regras preestabelecidas em ralação a como construir tais estruturas de dados. Nesse sentido, visando abranger o problema de forma mais generalizada, os arquivos de entrada suportam qualquer matriz de tamanho MxN, porém, tais dados devem ser organizados de formas bem específicas.
    </p>
    <div>
        <h3>🏃‍♂️💨 Caminhando nas matrizes</h3>
    </div>
    <div>
        <h3>📨 Arquivos de entrada</h3>
        <p>
            Os arquivos utilizados para armazenar as matrizes devem ser do tipo <strong>Arquivo DATA</strong> (.data) ou <strong>Documento de texto</strong> (.txt). Estes, por sua vez, podem armazenar a quantidade de matrizes que o usuário desejar, desde que seus elementos sejam organizados de acordo com três possíveis modelos: I) Matrizes quadradas, II) Matrizes quadradas variadas e III) Matrizes dinâmicas.
        </p>
        <ol type="i">
            <li>
                <h4><i>Matrizes quadradas: </i></h4>
                <p>
                    Nesse padrão de entrada o sistema é capaz de incorporar apenas matrizes quadradas no tamanho NxN. Ou seja, todas as matrizes armazenadas nesse modelo devem possuir o mesmo numero de linhas e colunas.
                </p>
                <p>
                    Para representar as matrizes quadradas, é preciso declarar seus tamanhos fixos na primeira linha do arquivo de entrada. A seguir, na segunda linha de registro, é inserido os números da matriz,onde cada elemento deve ser separado por um espaço. Nesse sentido, a quantidade de números deve respeitar o tamanho (N N) informado na primeira linha do arquivo de entrada. Após isso, para armazenar outras matrizes basta separa-las por uma linha em branco.
                </p>
                <p>
                    Segue o exemplo de como criar um arquivo de entrada para uma matriz quadrada de tamanho 7X7 no Arquivo DATA <a href="https://github.com/LuanLuL/AEDS---Caminho-Guloso/blob/developer/input.data">input.data</a>. Para visualizar o método de leitura desse modelo de input acesse o main.cpp.
                </p>
                <code>ListMatrizes lerMatrizesQuadradas(string txt){...</code>
            </li>
            <li>
                <h4><i>Matrizes quadradas variadas: </i></h4>
                <p>
                    Esse modelo também sustenta a entrada matrizes quadradas no tamanho NxN, entretanto, diferente do primeiro padrão de entrada, neste cada matriz pode ter seu próprio tamanho. Ou seja, todas as matrizes armazenadas nesse modelo são quadradas, mas pode-se armazenar matrizes com dimensões distintas umas das outras.
                </p>
                <p>
                    Para inserir as matrizes quadradas variadas, é preciso declarar o número de seu tamanho na linha anterior à matriz. A seguir, na próxima linha de registro, é dado entrada aos números, onde cada elemento deve ser separado por um espaço. Nesse sentido, a quantidade de números deve respeitar o tamanho (N) informado para cada matriz. Após isso, para guardar mais matrizes basta repetir o esquema. Atenção, não pode haver nenhuma linha em branco nesse tipo de arquivo de entrada. 
                </p>
                <p>
                    Segue o exemplo de como criar um arquivo de entrada para uma matriz quadrada variada no Arquivo DATA <a href="https://github.com/LuanLuL/AEDS---Caminho-Guloso/blob/developer/input_2.data">input_2.data</a>. Para visualizar o método de leitura desse modelo de input acesse o main.cpp.
                </p>
                <code>ListMatrizes lerMatrizesQuadradasVariadas(string txt){...</code>
            </li>
            <li>
                <h4><i>Matrizes dinâmicas: </i></h4>
                <p>
                    Sendo o modelo mais completo, o terceiro padrão de entrada consegue ler matrizes dinâmicas de tamanho MxN. Ou seja, cada matriz pode ter seu respectivo número de linhas e colunas. Dessa forma o arquivo de dados é capaz de armazenar qualquer matriz que o usuário deseje incorporar no sistema.
                </p>
                <p>
                    Para armazenar as matrizes dinâmica, é preciso declarar, respectivamente, o número de linhas e colunas na linha anterior à matriz. Após isso, na próxima linha de registro, é dado colocado os números, onde cada elemento deve ser separado por um espaço. Lembre-se que a quantidade de números deve respeitar o tamanho (M N) informado para cada matriz. Caso seja necessário mais de uma matriz basta repetir o esquema. Atenção, não pode haver nenhuma linha em branco nesse tipo de arquivo de entrada.                    
                </p>
                <p>
                    Segue o exemplo de como criar um arquivo de entrada para matrizes dinâmica no Arquivo DATA <a href="https://github.com/LuanLuL/AEDS---Caminho-Guloso/blob/developer/input_3.data">input_3.data</a>. Para visualizar o método de leitura desse modelo de input acesse o main.cpp.
                </p>
                <code>ListMatrizes lerMatrizesDinamicas(string txt){...</code>
            </li>
        </ol>
    </div>
</section>
<section>
    <h2>✅ Solução<h2>
</section>