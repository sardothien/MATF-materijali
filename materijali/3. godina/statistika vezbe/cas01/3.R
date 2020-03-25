# Generisanje apsolutno neprekidnih slucajnih velicina.
# Neka je slucajna velicina X apsolutno neprekidnog tipa sa 
# funkcijom raspodele F. Tada slucajna velicina F(X) ima U[0, 1]
# raspodelu. Takodje, ako V ima U[0, 1] raspodelu i postoji
# inverz F^(-1), tada F^(-1)(V) ima funkciju raspodele F.

# Eksponencijalna raspodela
exp_random <- function(lambda){
  u <- runif(1)
  x <- (-1 / lambda) * log(1-u)
  return(x)
}

exp_random_samp <- function(lambda, N){
  u <- runif(N)
  x <- (-1 / lambda) * log(1-u)
  return(x)
}

exp_random_samp(0.2, 10)

# Erlangova raspodela y(lambda, n)
erlang_random <- function(n, lambda){
  x <- rexp(n, lambda)
  sum(x)
}

erlang_random(10, 2)