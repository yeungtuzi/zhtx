// d/xizang/class/budala/npc/yeqiu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIC"夜秋"NOR, ({"yeqiu","chaojing dizi","dizi"}));
	set("gender", "女性" );
	set("age", 35);
	set("attitude", "peaceful");
	set("title", "抄经弟子");
	set("long", "她是丹玛女活佛的弟子,正在辛苦地抄写经书.\n");
	set("combat_exp", 98765);
	create_family("布达拉宫", 15, "弟子");
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("zang-buddhi", 199);
	set_skill("literate", 110);
	set_skill("magic", 60);
	set_skill("essencemagic", 60);
	map_skill("magic", "essencemagic");

	set("inquiry", ([
		"格萨尔": "我见过他,不过是很久以前了.\n"
	]));
	set("chat_chance_combat", 80);
//        set("chat_msg_combat", ({
//		(: conjure_magic, "invocation" :)
//                (: conjure_magic, "protect" :)
//        }));

	setup();
	carry_object(__DIR__"obj/jiasha")->wear();
}
