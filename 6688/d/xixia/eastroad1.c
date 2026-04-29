// Room: /d/xixia/southroad1.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是一条宽阔的大马路，可以同时让五架马车并驾齐驱。
西边你看到了一个高耸的城楼被一条白带环绕着，原来这
里已经离西夏国的都城──中兴府不远了。
LONG
	);
	set("outdoors", "xixia");

        set("exits", ([ /* sizeof() == 2 */
        "northeast" : "/d/canyon/yizhan",
         "east" : "/d/canyon/camp1",
  	"north" : __DIR__"eshulin",
  	"west" : __DIR__"eastbridge",
]));

        setup();
}

int valid_leave(object me, string dir)
{
        object beggar;

        if (me->query_temp("tieshu") == 2 && dir == "north") {
                beggar = new(__DIR__"npc/dyingbeggar");
                beggar->unconcious();
                beggar->move(__DIR__"eshulin");
        }

        return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_swim", "swim");
	__DIR__"eastgate"->init();
}

int do_jump(string arg)
{
	string skill, desc, weapon_type;
        object me, river, wall, weapon;
        int lvl, coeff;

        if( !objectp(river = find_object(__DIR__"dhch")))
                if( !objectp(river = new(__DIR__"dhch")))
                        return 1;

        if( !objectp(wall = find_object(__DIR__"eastwall1")))
                if( !objectp(wall = new(__DIR__"eastwall1")))
                        return 1;

        me = this_player();

        weapon = me->query_temp("weapon");
        if (objectp(weapon))
                weapon_type = weapon->query("type");
        else    weapon_type = "unarmed";


        lvl = me->query_skill("move");
        if (stringp(skill = me->query_skill_mapped("move"))) {
                coeff = SKILL_D(skill)->effective_level();
                if( coeff > 0 )
                lvl = lvl * coeff / 10;
        }
        coeff = me->query_encumbrance() * 100 / me->query_max_encumbrance();
        lvl = lvl * (100 - coeff) / 100;

	if (me->query("force") < 200)
		return notify_fail("你的内力不够，无法跳上城墙！\n");

	me->add("force", -200);

	if (lvl < 260 || (lvl <= 350 && (weapon_type == "unarmed" || weapon_type == "dagger" || weapon_type == "throwing"))) {
		message_vision("$N纵身向城墙上跃去，结果在半空中又落了下来。\n", me);
		if( lvl > 170 ) {
			message_vision(HIY"结果扑通一下掉到了河里，摔了个四脚朝天！\n"NOR, me);
			me->move(river);
			tell_room(river, HIY"只听见扑通一声，" + me->name() + "从上面掉了下来，摔了个四脚朝天。\n"NOR, me);
			me->receive_damage("kee", 100);
			COMBAT_D->report_status(me, me, 0);
		}

		return 1;
	}

	switch( skill ) {
		case "stormdance":
                        desc = "嫦娥奔月"; break;
                case "tiyunzong":
                        desc = "白鹤冲天"; break;
                case "tie-steps":
                        desc = "开天势"; break;
                case "huashan-shenfa":
                        desc = "旭日初升"; break;
                case "baguabu":
                        desc = "天字决"; break;
                case "xiaoyaoyou":
                        desc = "细胸巧翻云"; break;
                case "mo-shan-jue":
                        desc = "心随雁飞灭"; break;
                case "zhutian":
                        desc = "日月扣"; break;
                case "pyrobat-steps":
                        desc = "火蝠曳空"; break;
                case "xianyun":
                        desc = "巧燕穿云"; break;
                case "notracesnow":
                        desc = "鱼翔蓝天"; break;
                case "fall-steps":
                        desc = "怀佳人兮不能忘"; break;
                case "fx-step":
                        desc = "羽扇纶巾"; break;
                case "shaolin-shenfa":
                        desc = "苍龙出水"; break;
                case "chaos-steps":
                        desc = "逐影天枢"; break;
                default:
                        desc = "细胸巧翻云";
        }

	message_vision(HIG"$N右足连点数下， 一式「" + desc + "」，半空中连翻数翻，姿势变幻莫测，\n令人眼花聊乱，朝着城楼上飞去！\n"NOR, me);
	tell_room(wall, HIG"只见一个人影恍似一只飞燕，又向一只大鹏，朝着城楼上飞来！\n"NOR);
	if( lvl > 450 ) {
		tell_room(wall, HIG"待到飘至城墙上空，却见那人影并不立刻降落，而是继续飘呀，飘呀，向着城内飘去！\n"NOR);
                write(HIG"待到飘至城墙上空，并不立刻降落，而是继续向城内飘去！\n"NOR);

		me->move(__DIR__"eastgate");
		tell_room(environment(me), HIY + me->name() + "突然出现在你面前，竟不知从何而来！\n"NOR, me);
		return 1;
	}

	if( lvl > 350 ) {
		me->move(wall);	
		message_vision(HIG"$N稳稳当当地落在了城楼上，轻功之高，世间罕见！\n"NOR, me);
		message_vision(HIR"\n守卫们一个个呆立当场，恍若木鸡，直不信人世间竟有此等奇观！\n"NOR, me);

		return 1;
	}	

	tell_room(environment(me), HIG"将近城楼之际，眼见就要落下去，却见白光一闪，" + me->name() + "手中" + weapon->name() + HIG"在城墙上一搭，身形登时陡然拔高丈余，稳稳当当地降落在了城楼上，轻功之高，实令人匪夷所思！\n"NOR, me);
	tell_room(wall, HIG"将近城楼之际，眼见就要落下去，却见白光一闪，那人手中" + weapon->name() + HIG"只在城墙上一搭，身形登时陡然拔高丈余，稳稳当当地降落在了城楼上，轻功之高，实令人匪夷所思！\n"NOR);
	write(HIG"将近城楼之际，眼见就要落下去，你抽出" + weapon->name() + HIG"在城墙上一搭，身形登时陡然拔高丈余，稳稳当当地降落在了城楼上。\n"NOR);

	me->move(wall);
	message_vision(HIG"守卫们一个个呆立当场，恍若木鸡，直不信人世间竟有此等奇观！\n"NOR, me);
	return 1;
}

int do_swim(string arg)
{
        object me;

        me = this_player();

        if (me->query_skill("swiming"))
                message_vision("$N走到护城河边，向着城墙边游了过去。\n", me);
        else {
                if( me->query("force") < 100 ) {
                        write("你不会游泳，又没了内力运龟息功，会淹死的！\n");
                        return 1;
                }
                me->add("force", -100);
                tell_object(me, "你深吸一口气，运起龟息功，朝着护城河里走了过去。\n");
                tell_room(this_object(), me->name() + "深深吸了一口气，然后朝着>护城河里奋不顾身得走了过去，不会游泳？！\n", me);
        }

        me->start_busy(1);
        call_out("arrived", 1, me);

        return 1;
}

void arrived(object me)
{
        me->move(__DIR__"dhch");

        message_vision("$N终于到了城墙下面,双手抠住墙角的洞眼，深深地透了口气。\n", me);
}
