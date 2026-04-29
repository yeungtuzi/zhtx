//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大殿");
	set("long", @LONG
	 这里当中是如来佛祖的神像，旁边是观音大士与菩提老祖，神像前的
供桌上摆满了供品，桌子前的香炉里满是香烟。地上整整齐齐的排放着数十个黄
布蒲团，东首有一个红木讲坛，讲坛上放着个竹制的木鱼。左右两边各放着一对
美轮美奂的大花瓶，上插檀香数枝，香烟缭绕，氤氲芬芳，室内一片祥和之气。
看来这里是香客们进香及寺内高僧日常对僧众讲经说法的地方。
LONG
);
	set("exits", ([
		"northdown" : __DIR__"s_hssht",
		"southdown" : __DIR__"s_hssqt",
		"east" : __DIR__"s_slt",
]));   
	set("objects",([
	__DIR__"npc/xiang-ke" : 2,
	]));                         
	setup();
}





