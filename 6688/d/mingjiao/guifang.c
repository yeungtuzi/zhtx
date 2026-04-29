
inherit ROOM;

int do_push(string arg);

void create()
{
	set("short", "闺房");
	set("long", @LONG
	这是赵敏的闺房，一股幽香扑面而来。中堂一幅手绘“八骏图”，
八驹姿态各不相同，匹匹神骏风发。 左壁悬着一幅大字，文曰：“白虹座
上飞，青蛇匣中吼，杀杀霜在锋，团团月临纽。 剑决天外云，剑冲日中斗，
剑破妖人腹，剑拂佞臣首。潜将辟魑魅，勿但惊妾妇。留斩泓中蛟，莫试
街中狗。”诗末题了一行小字：“夜试倚天宝剑，洵神物也，杂 录‘说剑’
诗以赞之。汴梁赵敏。” 
	这幅字笔势纵横，然颇有妩媚之致，显是出自女子手笔。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	
        set("valid_startroom", 1);
        set("sleep_room",1);
        set("no_fight",1);
        set("no_poison",1);
        set("no_magic",1);

        setup();	
}
