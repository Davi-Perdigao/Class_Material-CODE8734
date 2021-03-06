local distanciamax = 20 -- distância máxima para que o NPC comece a correr

local distanciamin = 5 -- distância mínima que o NPC deve ser aproximar

function jogador() -- inicia função chamada jodagor
        repeat
                wait()
        until game.Players.NumPlayers >= 1 -- verifica se existem jogadores em cena para iniciar

        local NPC = script.Parent -- identifica que o NPC é quem está com o componente script

        local NPCHumanoidRoot = NPC.HumanoidRootPart -- define qual parte do NPC vai ser usada de referência para calcular a distância

        local NPCHumanoid = NPC.Humanoid -- salva o componente Humanoid do NPC em um parâmetro

        for l, v in pairs(game.Players:GetPlayers()) do -- pega a lista de jogadores para saber atrás de quem têm que correr
                repeat
                        wait()
                until v.Character
                if
                        (v.Character.HumanoidRootPart.Position - NPCHumanoidRoot.Position).Magnitude <= distanciamax and
                                (v.Character.HumanoidRootPart.Position - NPCHumanoidRoot.Position).Magnitude >=
                                        distanciamin
                 then -- verifica se o NPC está entre a distância máxima e distância mínima
                        NPCHumanoid:MoveTo(v.Character.HumanoidRootPart.Position - Vector3.new(0, 5, 0)) -- movimenta o NPC para se aproximar do jogador caso estiver dentro da distância máxima e mínima
                end -- end do if
        end -- end do for
end -- end da função

while wait() do
        jogador() -- chama a função jogador
end -- end do while
