const CubeConundrum = (games) => {
  return games.reduce((acc, game, index) => {
    return ( acc + (!game.substr(game.indexOf(":") + 2).split("; ").map(subset => {
      return subset.split(", ").every((part) => {
        const [num, color] = part.split(" ")
        return (
          (color === "red" && parseInt(num) <= 12) ||
          (color === "green" && parseInt(num) <= 13) ||
          (color === "blue" && parseInt(num) <= 14)
        )
      })
    }).includes(false) ? index + 1 : 0))
  }, 0)
}

module.exports = CubeConundrum