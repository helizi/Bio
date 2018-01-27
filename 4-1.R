global <- read.csv(file = "~/CLionProjects/untitled/global.csv", check.names = FALSE)
distances <- global
lens <- c(18891, 18875, 18935, 18955, 18940)
for (i in 1:5){
  for(j in 1:i){
    distances[[i,j]] <- -(3/4)*1/(1.9 * 10^(-3))*log(1 - 4/3 * global[[i,j]]/((lens[i] + lens[j])/2))
    distances[[j,i]] <- distances[[i,j]]
  }
}
distances