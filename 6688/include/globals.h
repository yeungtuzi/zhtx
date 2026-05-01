//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)
#ifndef __GLOBALS_H__
#define __GLOBALS_H__

// Directories

#define COMMAND_DIR             "/cmds/"
#define CONFIG_DIR              "/adm/etc/"
#define DATA_DIR                "/data/"
#define HELP_DIR                "/doc/"
#define LOG_DIR                 "/log/"
#define OBJ_DIR                 "/obj/"
#define NPC_DIR                 "/obj/npc/"
#define USER_WEAP_DIR           "/std/userdefine/weapon/"
#define USER_CLOTH_DIR          "/std/userdefine/cloth/"
#define USER_ROOM               "/std/userdefine/house.c"
#define USER_ROOM_TEMPLETE      "/std/userdefine/housetemplete.c"
#define USER_ROOM_DATA_DIR      "/data/room/"

// Daemons

#define ALIAS_D                 "/adm/daemons/aliasd"
#define CHANNEL_D               "/adm/daemons/channeld"
#define CHAR_D                  "/adm/daemons/chard"
#define CHINESE_D               "/adm/daemons/chinesed"
#define GTIME_D                 "/adm/daemons/gtimed.c"
#define COMBAT_D                "/adm/daemons/combatd"
#define COMMAND_D               "/adm/daemons/cmd_d"
#define EMOTE_D                 "/adm/daemons/emoted"
#define FINGER_D                "/adm/daemons/fingerd"
#define INQUIRY_D               "/adm/daemons/inquiryd"
#define LOGIN_D                 "/adm/daemons/logind"
#define MONEY_D                 "/adm/daemons/moneyd"
#define NATURE_D                "/adm/daemons/natured"
#define PART_D                  "/adm/daemons/partd.c"
#define PIG_D                   "/adm/daemons/pigd.c"
#define PROFILE_D               "/adm/daemons/profiled"
#define RANK_D                  "/adm/daemons/rankd"
#define GLOBAL_D                "/adm/daemons/globald"
#define NEWS_D                "/adm/daemons/newsd"
#define SECURITY_D              "/adm/daemons/securityd"
#define UPDATE_D                "/adm/daemons/updated"
#define VIRTUAL_D               "/adm/daemons/virtuald"
#define WELCOME_D               "/adm/daemons/welcomed"
#define WEAPON_D                "/adm/daemons/weapond"
#define REPLACE_D               "/adm/daemons/replaced"
#define FINANCE_D               "/adm/daemons/financed"

#define CLASS_D(x)              ("/class/" + x)
#define CONDITION_D(x)  ("/daemon/condition/" + x)
#define RACE_D(x)               ("/adm/daemons/race/" + x)
#define SKILL_D(x)              (call_other("/adm/daemons/skilld", "query_skill_daemon", x))

// Clonable/Non-inheritable Standard Objects

#define COIN_OB                 "/obj/money/coin"
#define CORPSE_OB               "/obj/user/corpse"
#define GOLD_OB                "/obj/money/gold"
#define LOGIN_OB                "/obj/user/login"
#define MASTER_OB               "/adm/obj/master"
#define MAILBOX_OB              "/obj/misc/mailbox"
#define SILVER_OB               "/obj/money/silver"
#define THCASH_OB               "/obj/money/thousand-cash"
#define TECASH_OB               "/obj/money/tenthousand-cash"
#define SIMUL_EFUN_OB           "/adm/obj/simul_efun"
#define USER_OB                 "/obj/user/user"   
#define WIZUSER_OB              "/obj/user/wiz"
#define VOID_OB                 "/obj/misc/void"

// Inheritable Standard Objects

#define C_GUILD         "/std/room/c_guild"
#define BANK                    "/std/room/bank"
#define BULLETIN_BOARD  "/std/bboard"
#define CHARACTER               "/std/char"
#define CLASS_GUILD             "/std/room/class_guild"
#define COMBINED_ITEM   "/std/item/combined"
#define EQUIP                   "/std/equip"
#define FORCE                   "/std/force"
#define HOCKSHOP                "/std/room/hockshop"
#define ITEM                    "/std/item"
#define LIQUID_ITEM             "/std/item/liquid"
#define MONEY                   "/std/money"
#define NPC                             "/std/char/npc"
#define POWDER                  "/std/medicine/powder"
#define ROOM                    "/std/room"
#define SKILL                   "/std/skill"
#define SSERVER                 "/std/sserver"
#define B_HOUSE                 "/std/room/b_house"

// User IDs

#define ROOT_UID                "mudadm"
#define BACKBONE_UID            "Backbone"

// Features

#define F_ACTION                "/feature/action.c"
#define F_ALIAS                 "/feature/alias.c"
#define F_ARRAYS                "/feature/array.c"
#define F_ATTACK                "/feature/attack.c"
#define F_ATTRIBUTE             "/feature/attribute.c"
#define F_AUTOLOAD              "/feature/autoload.c"
#define F_CLEAN_UP              "/feature/clean_up.c"
#define F_COMMAND               "/feature/command.c"
#define F_CONDITION             "/feature/condition.c"
#define F_DAMAGE                "/feature/damage.c"
#define F_DBASE                 "/feature/dbase.c"
#define F_EDIT                  "/feature/edit.c"
#define F_EQUIP                 "/feature/equip.c"
#define F_FAMILY                "/feature/family.c"
#define F_FINANCE               "/feature/finance.c"
#define F_FOOD                  "/feature/food.c"
#define F_LIQUID                "/feature/liquid.c"
#define F_MESSAGE               "/feature/message.c"
#define F_MORE                  "/feature/more.c"
#define F_MOVE                  "/feature/move.c"
#define F_NAME                  "/feature/name.c"
#define F_REPORT                "/feature/report.c"
#define F_SAVE                  "/feature/save.c"
#define F_SSERVER               "/std/sserver.c"
#define F_SKILL                 "/feature/skill.c"
#define F_TEAM                  "/feature/team.c"
#define F_TREEMAP               "/feature/treemap.c"
#define F_TRIGGER               "/feature/trigger.c"
#define F_UNIQUE                "/feature/unique.c"

// for quest
#define F_QUEST                 "/std/char/quest.c"
#define F_MASTER                "/std/char/master.c"
#define F_MERCENARY             "/std/char/mercenary.c"
#define F_VENDOR                "/std/char/vendor.c"
#define F_DEALER                "/std/char/dealer.c"

// for 宗师
#define ZONGSHI_NPC             "/std/char/zongshi.c"

// for alias and trigger
#define F_ALIAS                 "/feature/alias.c"
#define F_TRIGGER               "/feature/trigger.c"

//other
#define F_EMAIL                 "/feature/mail.c"
#define F_VI                    "/feature/vi.c"

// Some other useful things 
// 尝试登录次数
#define MAX_LOGIN_RETRY 3
// 管理员联系方式       
#define ADMIN_EMAIL "mudadm@rock.ncic.ac.cn"
#define ADMIN_IP "127.0.0.1"
// 外部mail程序
#define MAILER "/usr/bin/sendmail"
// 临时文件,供外部程序查询.
#define CF_LOGIN "/adm/tmp/.login"
// 天赋总和
#define MAX_TOTAL_GIFTS 180
// 随机生成密码的种子
#define PWDSEED "abcdefghigjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"
// 用户注册确认信件
#define CONFIRM_MAIL "/adm/etc/confirm.mail"    
// 用户使用协议
#define USER_LICENSE "/data/license"
// 用户的存活期限(天)       
// 未注册通过
#define LIFE4GUEST 14
// 普通用户
#define LIFE4USER 120
// 帐号保留
#define LIFE4EVER 999

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS

#endif // __GLOBALS_H__
