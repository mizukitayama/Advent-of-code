const CubeConundrum = (games) => {
  return games.reduce((acc, game, index) => {
    return ( acc + (game.substr(game.indexOf(":") + 2).split("; ").map(subset => {
      return subset.split(", ").every((part) => {
        const [num, color] = part.split(" ")
        return (
          (color === "red" && parseInt(num) <= 12) ||
          (color === "green" && parseInt(num) <= 13) ||
          (color === "blue" && parseInt(num) <= 14)
        )
      })
    }).includes(false) ? 0 : index + 1))
  }, 0)
}

const CubeConundrumPart2 = (games) => {
  return games.reduce((acc, game) => {
    let [maxRed, maxGreen, maxBlue] = [0, 0, 0]
    game.substr(game.indexOf(":") + 2).split("; ").forEach(subset => {
      subset.split(", ").forEach((part) => {
        let [num, color] = part.split(" ")
        num = parseInt(num)
        if (color === "red") maxRed = maxRed < num ? num : maxRed
        if (color === "green") maxGreen = maxGreen < num ? num : maxGreen
        if (color === "blue") maxBlue = maxBlue < num ? num : maxBlue
      })
    })
    return acc + (maxRed * maxGreen * maxBlue)
  }, 0)
}

module.exports = {
  CubeConundrum,
  CubeConundrumPart2
} 