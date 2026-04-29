// banker.c
// changed by dwolf

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("相国福", ({"xiang guofu", "xiang" }));
	set("title", MAG"钱庄老板"NOR);
	set("nickname", YEL"富比王侯"NOR);
	set("gender", "男性"); 

	set("long", 
	"相国福从小继承成祖业，过着逍遥的日子，养成了傲慢的性子，但他心地还是挺好的。\n");    
	set("age", 35);
	set("str", 26);
	set("int", 30);
	set("dex", 25);
	set("con", 24);

	set("kee", 600); 
	set("max_kee", 600);
	set("gin", 200);
	set("max_gin", 200);

	set("combat_exp", 100000);
	set("attitude", "peacful");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	YEL"相国福傲然一笑，本钱庄已有二百多年历史，信誉卓著，你尽管放心。\n"NOR,
	YEL"相国福淡淡地说道：在本店存钱取十分之一的利息，手续费就免了，阁下您看着办吧。\n"NOR,   
	HIW"相国福忽然叹了一口气:什么时候我也能向玩家一样去纵横江湖，快意恩仇，那该多好啊！\n"NOR,
	}));

	set_skill("unarmed", 70);
	set_skill("dodge", 70); 
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	add_money("gold", 1);
}

