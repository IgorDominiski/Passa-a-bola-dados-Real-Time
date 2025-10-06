# 🚀 Guia de Instalação - Passa a Bola IoT

Este guia fornece instruções detalhadas para instalar e executar o projeto Passa a Bola com integração IoT.

## 📋 Pré-requisitos

### Obrigatórios
- **Navegador web moderno** (Chrome 80+, Firefox 75+, Safari 13+, Edge 80+)
- **Conexão com internet** (para MQTT e CDNs)

### Opcionais (para funcionalidades avançadas)
- **Python 3.6+** (para servidor local)
- **Node.js 14+** (para testes MQTT avançados)
- **Git** (para controle de versão)

## 🔧 Instalação Rápida

### 1. Clone o Repositório
```bash
git clone https://github.com/seu-usuario/passa-a-bola.git
cd passa-a-bola
```

### 2. Verificar Dependências
```bash
# Executar script de verificação
./scripts/check-dependencies.sh
```

### 3. Executar o Projeto
```bash
# Opção 1: Python (recomendado)
python3 -m http.server 8000

# Opção 2: Node.js
npx http-server -p 8000

# Opção 3: Abrir diretamente (sem servidor)
open home.html
```

### 4. Acessar o Projeto
- **Homepage**: http://localhost:8000
- **Página IoT**: http://localhost:8000/iot.html

## 🐍 Instalação com Python

### Ubuntu/Debian
```bash
sudo apt update
sudo apt install python3 python3-pip
```

### macOS
```bash
# Com Homebrew
brew install python3

# Ou baixar do site oficial
# https://www.python.org/downloads/
```

### Windows
```bash
# Baixar do site oficial
# https://www.python.org/downloads/
# Marcar "Add Python to PATH" durante a instalação
```

### Executar
```bash
python3 -m http.server 8000
```

## 🟢 Instalação com Node.js

### Ubuntu/Debian
```bash
curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash -
sudo apt-get install -y nodejs
```

### macOS
```bash
# Com Homebrew
brew install node

# Ou baixar do site oficial
# https://nodejs.org/
```

### Windows
```bash
# Baixar do site oficial
# https://nodejs.org/
```

### Instalar Dependências
```bash
npm install
```

### Executar
```bash
npm start
# ou
npx http-server -p 8000
```

## 🔌 Configuração MQTT

### 1. Configuração Básica
O projeto já está configurado para usar o broker público `test.mosquitto.org:8081`.

### 2. Configuração Personalizada
```bash
# Copiar arquivo de configuração
cp config/mqtt.example.js config/mqtt.js

# Editar configurações
nano config/mqtt.js
```

### 3. Testar Conectividade MQTT
```bash
# Teste básico
./scripts/test-mqtt.sh

# Teste avançado (requer Node.js)
npm test
```

## 🧪 Testes e Verificação

### Verificar Dependências
```bash
./scripts/check-dependencies.sh
```

### Testar MQTT
```bash
./scripts/test-mqtt.sh
```

### Deploy Completo
```bash
./scripts/deploy.sh
```

## 🐛 Solução de Problemas

### Problema: "Comando não encontrado"
```bash
# Verificar se o comando está no PATH
which python3
which node
which git

# Adicionar ao PATH se necessário
export PATH=$PATH:/usr/local/bin
```

### Problema: "Porta 8000 em uso"
```bash
# Usar porta diferente
python3 -m http.server 8001
# ou
npx http-server -p 8001
```

### Problema: "MQTT não conecta"
```bash
# Verificar conectividade
ping test.mosquitto.org

# Verificar firewall
telnet test.mosquitto.org 8081
```

### Problema: "Arquivos não carregam"
```bash
# Verificar permissões
chmod +x scripts/*.sh

# Verificar estrutura
ls -la
```

## 📱 Testando em Dispositivos Móveis

### 1. Encontrar IP Local
```bash
# Linux/macOS
ifconfig | grep inet

# Windows
ipconfig
```

### 2. Acessar do Mobile
```
http://SEU_IP:8000
http://SEU_IP:8000/iot.html
```

### 3. Testar Responsividade
- Abrir DevTools (F12)
- Modo responsivo (Ctrl+Shift+M)
- Testar diferentes resoluções

## 🔒 Configurações de Segurança

### HTTPS Local (Opcional)
```bash
# Gerar certificado SSL
openssl req -x509 -newkey rsa:4096 -keyout key.pem -out cert.pem -days 365 -nodes

# Executar com HTTPS
python3 -m http.server 8000 --bind 0.0.0.0
```

### Firewall
```bash
# Ubuntu/Debian
sudo ufw allow 8000

# macOS
sudo pfctl -f /etc/pf.conf
```

## 📊 Monitoramento

### Logs do Servidor
```bash
# Python
python3 -m http.server 8000 2>&1 | tee server.log

# Node.js
npx http-server -p 8000 --log-ip
```

### Logs MQTT
```bash
# Verificar logs no console do navegador
# F12 -> Console
```

## 🚀 Deploy em Produção

### 1. Preparar Build
```bash
./scripts/deploy.sh
```

### 2. Configurar Servidor Web
```bash
# Nginx
sudo apt install nginx
sudo cp nginx.conf /etc/nginx/sites-available/passaabola
sudo ln -s /etc/nginx/sites-available/passaabola /etc/nginx/sites-enabled/
sudo systemctl restart nginx
```

### 3. Configurar SSL
```bash
# Certbot para Let's Encrypt
sudo apt install certbot python3-certbot-nginx
sudo certbot --nginx -d seu-dominio.com
```

## 📞 Suporte

### Problemas Comuns
1. **Porta ocupada**: Use porta diferente
2. **MQTT não conecta**: Verifique firewall
3. **Arquivos não carregam**: Verifique permissões
4. **Layout quebrado**: Limpe cache do navegador

### Logs de Debug
```bash
# Ativar logs detalhados
export DEBUG=mqtt:*
npm start
```

### Contato
- **Issues**: [GitHub Issues](https://github.com/seu-usuario/passa-a-bola/issues)
- **Email**: contato@passaabola.com
- **Discord**: [Servidor da Comunidade](https://discord.gg/passaabola)

## ✅ Checklist de Instalação

- [ ] Repositório clonado
- [ ] Dependências verificadas
- [ ] Servidor local executando
- [ ] Página inicial carregando
- [ ] Página IoT funcionando
- [ ] MQTT conectando
- [ ] Dados atualizando
- [ ] Responsividade testada

---

**🎉 Parabéns! Seu projeto Passa a Bola IoT está funcionando!**

Para mais informações, consulte o [README.md](README.md) principal.
