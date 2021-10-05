local portaAberta = false

function abrirPorta()
    if portaAberta == false then
        script.Parent.PortaFechada.MacanetaFora.Transparency = 1

        script.Parent.PortaFechada.MacanetaDentro.Transparency = 1

        script.Parent.PortaFechada.Porta.Transparency = 1

        script.Parent.PortaFechada.MacanetaFora.CanCollide = false

        script.Parent.PortaFechada.MacanetaDentro.CanCollide = false

        script.Parent.PortaFechada.Porta.CanCollide = false

        script.Parent.PortaAberta.MacanetaFora.Transparency = 0

        script.Parent.PortaAberta.MacanetaDentro.Transparency = 0

        script.Parent.PortaAberta.Porta.Transparency = 0

        script.Parent.PortaAberta.MacanetaFora.CanCollide = true

        script.Parent.PortaAberta.MacanetaDentro.CanCollide = true

        script.Parent.PortaAberta.Porta.CanCollide = true

        portaAberta = true
    else
        script.Parent.PortaFechada.MacanetaFora.Transparency = 0

        script.Parent.PortaFechada.MacanetaDentro.Transparency = 0

        script.Parent.PortaFechada.Porta.Transparency = 0

        script.Parent.PortaFechada.MacanetaFora.CanCollide = true

        script.Parent.PortaFechada.MacanetaDentro.CanCollide = true

        script.Parent.PortaFechada.Porta.CanCollide = true

        script.Parent.PortaAberta.MacanetaFora.Transparency = 1

        script.Parent.PortaAberta.MacanetaDentro.Transparency = 1

        script.Parent.PortaAberta.Porta.Transparency = 1

        script.Parent.PortaAberta.MacanetaFora.CanCollide = false

        script.Parent.PortaAberta.MacanetaDentro.CanCollide = false

        script.Parent.PortaAberta.Porta.CanCollide = false

        portaAberta = false
    end
end

script.Parent.ClickDetector.MouseClick:Connect(abrirPorta)
