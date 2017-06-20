local initAi = require("LuaScripts.scripts.scriptInit")

name = initAi.getNameAi()
ai = AiPlayer.new(name)

ressources = {[0]="WOOD", [1]="STONE", [2]="GOLD"}
specialization = {[0]="WOOD_COLLECTOR", [1]="STONE_COLLECTOR", [2]="GOLD_COLLECTOR"}
resIter = 0
nbLoops = 0
phaseOfGame = 0
while true do
  start = ai:checkFrame()
  if start == 1 then
    ret = ai:getNbCollector()
    if ret < 2 then
      ai:createUnit("COLLECTOR")
    end
    ai:collect("WOOD")
  end
end

