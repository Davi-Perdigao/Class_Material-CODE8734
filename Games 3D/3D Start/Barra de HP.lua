local Player = game.Players.LocalPlayer

local Character = Player.Character

local Humanoid = Character:WaitForChild("Humanoid")

local Frame = script.Parent

Humanoid.Changed:connect(
    function()
        local H = Humanoid.Health / Humanoid.MaxHealth

        Frame.Size = UDim2.new(H, 0, 1, 0)
    end
)
