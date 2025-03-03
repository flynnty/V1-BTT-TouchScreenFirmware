#include "FeatureSettings.h"
#include "includes.h"

static uint16_t fe_cur_page = 0;

// parameter values

#define ITEM_TOGGLE_AUTO_NUM 3
const LABEL itemToggleAuto[ITEM_TOGGLE_AUTO_NUM] =
{
  LABEL_OFF,
  LABEL_ON,
  LABEL_AUTO
};

#define ITEM_TOGGLE_SMART_NUM 2
const LABEL itemToggleSmart[ITEM_TOGGLE_SMART_NUM] =
{
  LABEL_ON,
  LABEL_SMART
};

// add key number index of the items
typedef enum
{
<<<<<<< HEAD
  SKEY_ACK = 0,
  SKEY_CNC,
  SKEY_LASER,
  SKEY_INVERT_X,
  SKEY_INVERT_Y,
  SKEY_INVERT_Z,
  #ifdef PS_ON_PIN
    SKEY_POWER,
  #endif
  #ifdef FIL_RUNOUT_PIN
    SKEY_RUNOUT,
  #endif
  SKEY_SPEED,
  SKEY_STARTGCODE,
  SKEY_ENDGCODE,
  SKEY_CANCELGCODE,
  SKEY_PERSISTENTINFO,
  SKEY_FILELIST,
  #ifdef LED_COLOR_PIN
    SKEY_KNOB,
  #endif
  #ifdef LCD_LED_PWM_CHANNEL
    SKEY_LCD_BRIGHTNESS,
    SKEY_LCD_BRIGTHNESS_DIM,
    SKEY_LCD_DIM_IDLE_TIMER,
  #endif
  #ifdef ST7920_SPI
    SKEY_ST7920_FULLSCREEN,
  #endif
  SKEY_RESET_SETTINGS, // Keep reset always at the bottom of the settings menu list.
  SKEY_COUNT //keep this always at the end
}SKEY_LIST;

#define FE_PAGE_COUNT  (SKEY_COUNT+LISTITEM_PER_PAGE-1)/LISTITEM_PER_PAGE
int fe_cur_page = 0;

//
//set item types
//
LISTITEM settingPage[SKEY_COUNT] = {
  {ICONCHAR_TOGGLE_ON,  LIST_TOGGLE,        LABEL_TERMINAL_ACK,             LABEL_BACKGROUND  },
  {ICONCHAR_TOGGLE_ON,  LIST_TOGGLE,        LABEL_CNC_MODE,                 LABEL_BACKGROUND  },
  {ICONCHAR_TOGGLE_ON,  LIST_TOGGLE,        LABEL_LASER_MODE,               LABEL_BACKGROUND  },
  {ICONCHAR_TOGGLE_ON,  LIST_TOGGLE,        LABEL_INVERT_XAXIS,             LABEL_BACKGROUND  },
  {ICONCHAR_TOGGLE_ON,  LIST_TOGGLE,        LABEL_INVERT_YAXIS,             LABEL_BACKGROUND  },
  {ICONCHAR_TOGGLE_ON,  LIST_TOGGLE,        LABEL_INVERT_ZAXIS,             LABEL_BACKGROUND  },
=======
  SKEY_EMULATED_M600 = 0,
  SKEY_EMULATED_M109_M190,
  SKEY_EVENT_LED,
  SKEY_FILE_COMMENT_PARSING,
  SKEY_SERIAL_ALWAYS_ON,
  SKEY_SPEED,
  SKEY_AUTO_LOAD_LEVELING,
  SKEY_PROBING_Z_OFFSET,
  SKEY_Z_STEPPERS_ALIGNMENT,

>>>>>>> btt_main/master
  #ifdef PS_ON_PIN
    SKEY_PS_AUTO_SHUTDOWN,
  #endif

  #ifdef FIL_RUNOUT_PIN
    SKEY_FIL_RUNOUT,
  #endif

  SKEY_PL_RECOVERY,
  SKEY_PL_RECOVERY_HOME,
  SKEY_BTT_MINI_UPS,
  SKEY_START_GCODE_ENABLED,
  SKEY_END_GCODE_ENABLED,
  SKEY_CANCEL_GCODE_ENABLED,
  SKEY_RESET_SETTINGS,        // Keep reset always at the bottom of the settings menu list.
  SKEY_COUNT                  // keep this always at the end
} SKEY_LIST;

// perform action on button press
void updateFeatureSettings(uint8_t item_index)
{
  switch (item_index)
  {
    case SKEY_EMULATED_M600:
    case SKEY_EMULATED_M109_M190:
    case SKEY_EVENT_LED:
    case SKEY_FILE_COMMENT_PARSING:
      TOGGLE_BIT(infoSettings.general_settings, ((item_index - SKEY_EMULATED_M600) + INDEX_EMULATED_M600));
      break;

<<<<<<< HEAD
    case SKEY_CNC:
      infoSettings.cnc_mode = (infoSettings.cnc_mode + 1) % TOGGLE_NUM;
      settingPage[item_index].icon = toggleitem[infoSettings.cnc_mode];
     break;

    case SKEY_LASER:
      infoSettings.laser_mode = (infoSettings.laser_mode + 1) % TOGGLE_NUM;
      settingPage[item_index].icon = toggleitem[infoSettings.laser_mode];
     break;

    case SKEY_INVERT_X:
      infoSettings.invert_axis[X_AXIS] = (infoSettings.invert_axis[X_AXIS] + 1) % TOGGLE_NUM;
      settingPage[item_index].icon = toggleitem[infoSettings.invert_axis[X_AXIS]];
     break;
=======
    case SKEY_SERIAL_ALWAYS_ON:
      infoSettings.serial_always_on = (infoSettings.serial_always_on + 1) % ITEM_TOGGLE_NUM;
      break;
>>>>>>> btt_main/master

    case SKEY_SPEED:
      infoSettings.move_speed = (infoSettings.move_speed + 1) % ITEM_SPEED_NUM;
      break;

    case SKEY_AUTO_LOAD_LEVELING:
      infoSettings.auto_load_leveling = (infoSettings.auto_load_leveling + 1) % ITEM_TOGGLE_NUM;
      break;

    case SKEY_PROBING_Z_OFFSET:
      infoSettings.probing_z_offset = (infoSettings.probing_z_offset + 1) % ITEM_TOGGLE_NUM;
      break;

    case SKEY_Z_STEPPERS_ALIGNMENT:
      infoSettings.z_steppers_alignment = (infoSettings.z_steppers_alignment + 1) % ITEM_TOGGLE_NUM;
      break;

    #ifdef PS_ON_PIN
      case SKEY_PS_AUTO_SHUTDOWN:
        infoSettings.auto_shutdown = (infoSettings.auto_shutdown + 1) % ITEM_TOGGLE_AUTO_NUM;
        break;
    #endif

    #ifdef FIL_RUNOUT_PIN
      case SKEY_FIL_RUNOUT:
        infoSettings.runout ^= (1U << 0);
        break;
    #endif

    case SKEY_PL_RECOVERY:
      infoSettings.plr = (infoSettings.plr + 1) % ITEM_TOGGLE_NUM;
      break;

    case SKEY_PL_RECOVERY_HOME:
      infoSettings.plr_home = (infoSettings.plr_home + 1) % ITEM_TOGGLE_NUM;
      break;

    case SKEY_BTT_MINI_UPS:
      infoSettings.btt_ups = (infoSettings.btt_ups + 1) % ITEM_TOGGLE_NUM;
      break;

    case SKEY_START_GCODE_ENABLED:
    case SKEY_END_GCODE_ENABLED:
    case SKEY_CANCEL_GCODE_ENABLED:
      TOGGLE_BIT(infoSettings.send_gcodes, (item_index - SKEY_START_GCODE_ENABLED));
      break;

    case SKEY_RESET_SETTINGS:
      setDialogText(LABEL_SETTINGS_RESET, LABEL_SETTINGS_RESET_INFO, LABEL_CONFIRM, LABEL_CANCEL);
      showDialog(DIALOG_TYPE_ALERT, resetSettings, NULL, NULL);
      break;

    default:
      return;
  }
}  // updateFeatureSettings

// load values on page change and reload
void loadFeatureSettings(LISTITEM * item, uint16_t item_index, uint8_t itemPos)
{
  if (item_index < SKEY_COUNT)
  {
    switch (item_index)
    {
      case SKEY_EMULATED_M600:
      case SKEY_EMULATED_M109_M190:
      case SKEY_EVENT_LED:
      case SKEY_FILE_COMMENT_PARSING:
        item->icon = iconToggle[GET_BIT(infoSettings.general_settings, ((item_index - SKEY_EMULATED_M600) + INDEX_EMULATED_M600))];
        break;

<<<<<<< HEAD
      case SKEY_CNC:
        settingPage[item_index].icon = toggleitem[infoSettings.cnc_mode];
        break;

      case SKEY_LASER:
        settingPage[item_index].icon = toggleitem[infoSettings.laser_mode];
        break;

      case SKEY_INVERT_X:
        settingPage[item_index].icon = toggleitem[infoSettings.invert_axis[X_AXIS]];
=======
      case SKEY_SERIAL_ALWAYS_ON:
        item->icon = iconToggle[infoSettings.serial_always_on];
>>>>>>> btt_main/master
        break;

      case SKEY_SPEED:
        item->valueLabel = itemSpeed[infoSettings.move_speed].label;
        break;

      case SKEY_AUTO_LOAD_LEVELING:
        item->icon = iconToggle[infoSettings.auto_load_leveling];
        break;

      case SKEY_PROBING_Z_OFFSET:
        item->icon = iconToggle[infoSettings.probing_z_offset];
        break;

      case SKEY_Z_STEPPERS_ALIGNMENT:
        item->icon = iconToggle[infoSettings.z_steppers_alignment];
        break;

      #ifdef PS_ON_PIN
        case SKEY_PS_AUTO_SHUTDOWN:
          item->valueLabel = itemToggleAuto[infoSettings.auto_shutdown];
          break;
      #endif

      #ifdef FIL_RUNOUT_PIN
        case SKEY_FIL_RUNOUT:
        {
          LABEL sensorLabel = itemToggleSmart[GET_BIT(infoSettings.runout, 1)];
          item->valueLabel.index = (GET_BIT(infoSettings.runout, 0)) ? sensorLabel.index : LABEL_OFF ;
          break;
        }
      #endif

      case SKEY_PL_RECOVERY:
        item->icon = iconToggle[infoSettings.plr];
        break;

      case SKEY_PL_RECOVERY_HOME:
        item->icon = iconToggle[infoSettings.plr_home];
        break;

      case SKEY_BTT_MINI_UPS:
        item->icon = iconToggle[infoSettings.btt_ups];
        break;

      case SKEY_START_GCODE_ENABLED:
      case SKEY_END_GCODE_ENABLED:
      case SKEY_CANCEL_GCODE_ENABLED:
        item->icon = iconToggle[GET_BIT(infoSettings.send_gcodes, (item_index - SKEY_START_GCODE_ENABLED))];
        break;

      case SKEY_RESET_SETTINGS:
        break;

      default:
        break;
    }
  }
}  // loadFeatureSettings

void resetSettings(void)
{
  initSettings();
  storePara();
  popupReminder(DIALOG_TYPE_SUCCESS, LABEL_INFO, LABEL_SETTINGS_RESET_DONE);
}

void menuFeatureSettings(void)
{
  LABEL title = {LABEL_FEATURE_SETTINGS};

  // set item types
  LISTITEM settingPage[SKEY_COUNT] = {
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_EMULATED_M600,          LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_EMULATED_M109_M190,     LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_EVENT_LED,              LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_FILE_COMMENT_PARSING,   LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_SERIAL_ALWAYS_ON,       LABEL_BACKGROUND},
    {CHARICON_BLANK,       LIST_CUSTOMVALUE,   LABEL_MOVE_SPEED,             LABEL_NORMAL},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_AUTO_LOAD_LEVELING,     LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_PROBING_Z_OFFSET,       LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_Z_STEPPERS_ALIGNMENT,   LABEL_BACKGROUND},

    #ifdef PS_ON_PIN
      {CHARICON_BLANK,       LIST_CUSTOMVALUE,   LABEL_PS_AUTO_SHUTDOWN,       LABEL_OFF},
    #endif

    #ifdef FIL_RUNOUT_PIN
      {CHARICON_BLANK,       LIST_CUSTOMVALUE,   LABEL_FIL_RUNOUT,             LABEL_OFF},
    #endif

    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_PL_RECOVERY,            LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_PL_RECOVERY_HOME,       LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_BTT_MINI_UPS,           LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_START_GCODE_ENABLED,    LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_END_GCODE_ENABLED,      LABEL_BACKGROUND},
    {CHARICON_TOGGLE_ON,   LIST_TOGGLE,        LABEL_CANCEL_GCODE_ENABLED,   LABEL_BACKGROUND},
    // Keep reset settings always at the bottom of the settings menu list.
    {CHARICON_BLANK,       LIST_MOREBUTTON,    LABEL_SETTINGS_RESET,         LABEL_BACKGROUND}
  };

  uint16_t index = KEY_IDLE;
  SETTINGS now = infoSettings;

  listViewCreate(title, settingPage, SKEY_COUNT, &fe_cur_page, true, NULL, loadFeatureSettings);

  while (MENU_IS(menuFeatureSettings))
  {
    index = listViewGetSelectedIndex();

    if (index < SKEY_COUNT)
    {
      updateFeatureSettings(index);
      listViewRefreshItem(index);
    }

    loopProcess();
  }

  if (memcmp(&now, &infoSettings, sizeof(SETTINGS)))
  {
    storePara();
  }
}
