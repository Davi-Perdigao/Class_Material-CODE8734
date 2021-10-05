NPCHumanoidRoot.Touched:Connect(
    function(hit)
        if hit.Parent:FindFirstChild("Humanoid") then
            hit.Parent:FindFirstChild("Humanoid"):TakeDamage(100)
        end
    end
)
