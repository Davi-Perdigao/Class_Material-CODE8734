local NPC = game.Workspace.NPC

while true do
    wait(5)

    NPC.Humanoid:MoveTo(game.Workspace.Ponto1.Position)

    NPC.Humanoid.MoveToFinished:wait()

    wait(1)

    NPC.Humanoid:MoveTo(game.Workspace.Ponto2.Position)

    NPC.Humanoid.MoveToFinished:wait()

    wait(1)

    NPC.Humanoid:MoveTo(game.Workspace.Ponto3.Position)

    NPC.Humanoid.MoveToFinished:wait()

    wait(1)

    NPC.Humanoid:MoveTo(game.Workspace.Ponto4.Position)

    NPC.Humanoid.MoveToFinished:wait()

    wait(1)
end
