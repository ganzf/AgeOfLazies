local M = {}

local function getNameAi()
  print("GetAiPlayer")
  if #arg == 0
    then name = ""
    else
      name = arg[1]
    end
    print("Name : "..name);
    return name
  end

  M.getNameAi = getNameAi

  return M
