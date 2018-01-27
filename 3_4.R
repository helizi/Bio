CSV3_4 <- read.csv(file = "~/CLionProjects/untitled/3-4.csv", check.names = FALSE)

##3-4
nei_3_4 = nj(as.dist(CSV3_4))
png(filename="~/CLionProjects/untitled/NJ_3-4.png")
plot(nei_3_4)
dev.off()