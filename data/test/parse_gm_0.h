/* This is normally nested in `.itemTemplate: [...]' */
static const char JSON0[] = R"RAW_JSON(
    [ { "templateId": "V0001_POKEMON_BULBASAUR_NORMAL",
        "pokemon": {
          "uniqueId": "BULBASAUR",
          "modelScale": 1.09,
          "type1": "POKEMON_TYPE_GRASS",
          "type2": "POKEMON_TYPE_POISON",
          "camera": {
            "diskRadiusM": 0.5723,
            "cylinderRadiusM": 0.5,
            "cylinderHeightM": 0.763,
            "shoulderModeScale": 0.5
          },
          "encounter": {
            "baseCaptureRate": 0.2,
            "baseFleeRate": 0.1,
            "collisionRadiusM": 0.3815,
            "collisionHeightM": 0.654,
            "collisionHeadRadiusM": 0.2725,
            "movementType": "MOVEMENT_JUMP",
            "movementTimerS": 10.0,
            "jumpTimeS": 1.15,
            "attackTimerS": 29.0,
            "attackProbability": 0.1,
            "dodgeProbability": 0.15,
            "dodgeDurationS": 1.0,
            "dodgeDistance": 1.0,
            "cameraDistance": 3.75,
            "minPokemonActionFrequencyS": 0.2,
            "maxPokemonActionFrequencyS": 1.6
          },
          "stats": {
            "baseStamina": 128,
            "baseAttack": 118,
            "baseDefense": 111
          },
          "quickMoves": ["VINE_WHIP_FAST", "TACKLE_FAST"],
          "cinematicMoves": ["SLUDGE_BOMB", "SEED_BOMB", "POWER_WHIP"],
          "animTime": [1.6667, 0.6667, 1.6667, 1.8333, 0.0, 2.1667, 1.4,
                        1.466667],
          "evolution": ["IVYSAUR"],
          "evolutionPips": 1,
          "pokedexHeightM": 0.7,
          "pokedexWeightKg": 6.9,
          "heightStdDev": 0.0875,
          "weightStdDev": 0.8625,
          "familyId": "FAMILY_BULBASAUR",
          "candyToEvolve": 25,
          "kmBuddyDistance": 3.0,
          "modelHeight": 0.7,
          "evolutionBranch": [{
            "evolution": "IVYSAUR",
            "candyCost": 25,
            "form": "IVYSAUR_NORMAL"
          }],
          "modelScaleV2": 0.89,
          "form": "BULBASAUR_NORMAL",
          "buddyOffsetMale": [0.0, 0.0, 0.0],
          "buddyOffsetFemale": [0.0, 0.0, 0.0],
          "buddyScale": 19.0,
          "thirdMove": {
            "stardustToUnlock": 10000,
            "candyToUnlock": 25
          },
          "isTransferable": true,
          "isDeployable": true,
          "buddyGroupNumber": 2
        }
      }
    ]
  )RAW_JSON";

static const size_t JSON0_LEN = array_size( JSON0 );
