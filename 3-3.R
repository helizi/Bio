##global
library(phangorn)
Global <- read.csv(file = "~/CLionProjects/untitled/global.csv", check.names = FALSE)
globaltree = upgma(Global)
png(filename="~/CLionProjects/untitled/UPGMA_global.png")
plot(globaltree)
dev.off()
neiglobal = nj(as.dist(Global))
png(filename="~/CLionProjects/untitled/NJ_global.png")
plot(neiglobal)
dev.off()
