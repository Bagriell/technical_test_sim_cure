
# Technical test Sim&Cure



## compilation with g++

build   
`g++ -std=c++17 data.cpp main.cpp -o technical_test_sim_cure`

run  
`./technical_test_sim_cure <filename>`


## cmake 

build
```
mkdir build
cmake -S . -B ./build
cd build/
make
```

run  
`
./technical_test_sim_cure <filename>
`
## possible enhancement

- handle other than utf-8 caracters
- fix warning for multiline characters on dict declaraction for special caracters


