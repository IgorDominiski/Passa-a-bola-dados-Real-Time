# ⚽ Passa a Bola - Plataforma de Futebol Feminino com IoT

## 👥 Integrantes da Equipe
- **Igor Dominiski** - RM562055
- **Murillo Akira** - RM561886
- **Murilo Canestri** - RM564053

## 📋 Sobre o Projeto

O **Passa a Bola** é uma plataforma web completa dedicada ao futebol feminino brasileiro, integrada com tecnologias IoT para monitoramento em tempo real de sensores de velocidade e rotação. O projeto combina desenvolvimento web moderno com conectividade MQTT para criar uma experiência interativa e tecnológica.

## Link para o projeto

https://wokwi.com/projects/444088190423301121

## 🎯 Objetivos


- Criar uma plataforma web responsiva para o futebol feminino
- Implementar integração IoT com sensores em tempo real
- Desenvolver interface moderna e intuitiva
- Garantir conectividade MQTT para dados de sensores
- Fornecer experiência completa de monitoramento

## 🖼️ Screenshots de Integração IoT

### Página IoT em Funcionamento dentro passa a bola e fora
![IoT Dashboard](https://youtu.be/uhJ_Q9Jhq7M)
*Interface principal mostrando dados de velocidade e rotação em tempo real*

### Status de Conexão MQTT
![MQTT Status](![Screenshot_20251006_151205_MyMQTT](https://github.com/user-attachments/assets/30d02f14-513a-4a91-abc1-2539024a38c2)
)
*Indicador visual do status da conexão MQTT*

## 🛠️ Tecnologias Utilizadas

### Frontend
- **HTML5** - Estrutura semântica
- **CSS3** - Estilização moderna com Flexbox/Grid
- **JavaScript ES6+** - Interatividade e lógica
- **MQTT.js** - Conectividade IoT em tempo real

### IoT & Conectividade
- **MQTT Broker** - test.mosquitto.org (porta 8081)
- **WebSocket** - Conexão segura (WSS)
- **ESP32** - Dispositivo IoT (simulado no Wokwi)
- **Sensores** - Velocidade e rotação

### Design & UX
- **Design Responsivo** - Mobile-first approach
- **Tema Esportivo** - Verde, branco e cinza
- **Animações CSS** - Transições suaves
- **Glassmorphism** - Efeitos visuais modernos

## 🚀 Funcionalidades Implementadas

### 🌐 Plataforma Web
- ✅ **Homepage Responsiva** - Design moderno e adaptativo
- ✅ **Navegação Intuitiva** - Menu hambúrguer e dropdown
- ✅ **Seções Completas** - Times, jogos, comunidade, notícias
- ✅ **Footer Completo** - Links, redes sociais, informações legais
- ✅ **Carrossel Dinâmico** - Destaques com navegação automática

### 🔌 Integração IoT
- ✅ **Conexão MQTT** - Broker público test.mosquitto.org
- ✅ **WebSocket Seguro** - Conexão WSS na porta 8081
- ✅ **Tópico Personalizado** - passaabola/sensores
- ✅ **Dados em Tempo Real** - Velocidade (km/h) e rotação (rpm)
- ✅ **Interface Visual** - Cards com animações e status de conexão

## 📊 Resultados da PoC (Proof of Concept)

### ✅ Conectividade MQTT
- **Status**: ✅ Funcionando
- **Broker**: test.mosquitto.org:8081
- **Protocolo**: WebSocket Seguro (WSS)
- **Latência**: < 100ms
- **Reconexão**: Automática em caso de falha

### ✅ Interface IoT
- **Atualização**: Tempo real
- **Dados**: Velocidade e rotação
- **Visualização**: Cards animados
- **Status**: Indicador de conexão

## 🐛 Troubleshooting

### Problemas Comuns

#### Conexão MQTT Falha
```javascript
// Verificar se o broker está acessível
console.log('Testando conexão MQTT...');
```

#### Dados Não Atualizam
- Verificar tópico: `passaabola/sensores`
- Confirmar formato JSON dos dados
- Verificar logs do console

---
