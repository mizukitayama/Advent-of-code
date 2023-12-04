fun isAdjacentToSymbol(splitedLines: List<String>, firstIndex: Int, lastIndex: Int, rowIndex: Int): Boolean {
	val height = splitedLines.size
    val width = splitedLines[0].length
    val directions = listOf(-1, 0, 1)
    
    for (i in firstIndex..lastIndex) {
        for (dy in directions) { //たて
            for (dx in directions ) { //よこ
                if (dy == 0 && dx == 0) continue

                val nowY = rowIndex + dy
                val nowX = i + dx
               	if (nowY in 0 until height && nowX in 0 until width) { 
                    val char = splitedLines[nowY][nowX]
                    if (char != '.' && !char.isDigit()) {
                        return true
                    }
                }
            }
        }
    }
    return false
}

fun Part1(test: String) {
    val splitedLines = test.split("\n")
    val regex = "\\d+".toRegex() //数字
    var sum = 0
    
   splitedLines.forEachIndexed { rowIndex, line ->
        regex.findAll(line).forEach { match ->
            val num = match.value.toInt()
            val firstIndex = match.range.first
            val lastIndex = match.range.last
            if (isAdjacentToSymbol(splitedLines, firstIndex, lastIndex, rowIndex)) {
                sum += num
            }
        }
    }
   println(sum)
}

fun main() {
    val test = """467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598.."""  
    Part1(test)
}
