local potion = script.Parent

local HumanoidRoot = potion.PrimaryPart

HumanoidRoot.Touched:Connect(
    function(hit)
        if hit.Parent:FindFirstChild("Humanoid") then
            hit.Parent:FindFirstChild("Humanoid").Health = 100

            potion:Destroy()
        end
    end
)
