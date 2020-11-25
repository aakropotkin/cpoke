static const char JSON1[] = R"RAW_JSON(
    {
      "templateId": "COMBAT_V0309_MOVE_MIRROR_SHOT",
      "combatMove": {
        "uniqueId": "MIRROR_SHOT",
        "type": "POKEMON_TYPE_STEEL",
        "power": 35.0,
        "vfxName": "mirror_shot",
        "energyDelta": -35,
        "buffs": {
          "targetAttackStatStageChange": -1,
          "buffActivationChance": 0.3
        }
      }
    }
  )RAW_JSON";

static const size_t JSON1_LEN = array_size( JSON1 );
