# ELYRIA STORIES - PSP Homebrew Game

## Description
Jeu de type GTA pour PSP/PPSSPP
Deux pays : ETATS-UNIS et ELYRIA

## Personnages
- **Josias** - Leadership et endurance
- **Franck** - Pilotage et vitesse
- **Mikael** - Precision et strategie
- **Trev** - Force et destruction

## Fonctionnalites
- Monde ouvert USA + ELYRIA
- 70 missions solo et groupe
- 6 braquages majeurs
- Coup d etat en 6 phases
- Braquage du siecle en 7 phases
- Arsenal national avec miniguns
- 26 vehicules + motos + bateaux
- 62 voitures de luxe
- 65 voitures classiques
- Systeme de vol avion et helicoptere
- Frontiere avec douaniers
- Casino poker blackjack roulette
- Coiffeur tatoueur boutiques
- Meteo dynamique jour/nuit
- Radio 6 stations funk hiphop rnb
- Systeme telephone messagerie
- 16 codes de triche
- 15 succes a debloquer
- 4 fins differentes

## Structure
cat > /workspaces/GTA/README.md << 'EOF'
# ELYRIA STORIES - PSP Homebrew Game

## Description
Jeu de type GTA pour PSP/PPSSPP
Deux pays : ETATS-UNIS et ELYRIA

## Personnages
- **Josias** - Leadership et endurance
- **Franck** - Pilotage et vitesse
- **Mikael** - Precision et strategie
- **Trev** - Force et destruction

## Fonctionnalites
- Monde ouvert USA + ELYRIA
- 70 missions solo et groupe
- 6 braquages majeurs
- Coup d etat en 6 phases
- Braquage du siecle en 7 phases
- Arsenal national avec miniguns
- 26 vehicules + motos + bateaux
- 62 voitures de luxe
- 65 voitures classiques
- Systeme de vol avion et helicoptere
- Frontiere avec douaniers
- Casino poker blackjack roulette
- Coiffeur tatoueur boutiques
- Meteo dynamique jour/nuit
- Radio 6 stations funk hiphop rnb
- Systeme telephone messagerie
- 16 codes de triche
- 15 succes a debloquer
- 4 fins differentes

## Structure


cd /workspaces/GTA && git add . && git commit -m "docs: README complet Elyria Stories" && git push

mkdir -p /workspaces/GTA/.github/workflows && cat > /workspaces/GTA/.github/workflows/build.yml << 'EOF'
name: Build Elyria Stories PSP

on:
  push:
    branches: [ main ]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3

    - name: Install PSP SDK
      run: |
        sudo apt-get update
        sudo apt-get install -y cmake build-essential
        wget https://github.com/pspdev/pspdev/releases/download/latest/pspdev-ubuntu-latest.tar.gz
        sudo tar -xzf pspdev-ubuntu-latest.tar.gz -C /usr/local/
        echo "/usr/local/pspdev/bin" >> $GITHUB_PATH

    - name: Build Game
      run: |
        export PSPDEV=/usr/local/pspdev
        mkdir -p build && cd build
        cmake .. -DCMAKE_TOOLCHAIN_FILE=$PSPDEV/psp/share/pspdev.cmake
        make

    - name: Upload ISO
      uses: actions/upload-artifact@v3
      with:
        name: elyria-stories-psp
        path: build/ELYRIA_STORIES.PBP
