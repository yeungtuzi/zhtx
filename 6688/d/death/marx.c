// This is roar's room

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "马克思的房间");
	set("ghostplace",1);
	set("long", @LONG
这里看起来就象个很大的工厂，到处都是机器，又象是个实验室，实验仪器
摆得到处都是。只有摆在主人面前写字台上的电脑和旁边书架上满满的书才显
出主人的真实身份。书架上的书籍分属近二十种语言。但都杂乱的放在一起，
显然无论哪本书主人都能拿起来就读。坐在电脑边上的是一个长着一脸络腮胡
子的中年人，显然他正沉浸在忘我的工作中。他的妻子坐在他旁边，静静地看
着他，偶尔递上一杯咖啡，眼里充满了柔情。电脑桌上边的横幅写着几个大字：
无论我是生是死，我都要研究这世界的规律。
LONG
	);
	set("exits",([
		"back" : __DIR__"deathhall",
	]));
        set("ghostplace",1);

	setup();
/*	replace(ROOM);*/
}
