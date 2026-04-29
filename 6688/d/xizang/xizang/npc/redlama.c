// /d/xizang/npc/redlama.c

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
	set_name("赤松", ({ "chi song", "song", "chi_song_lama" }) );
	set("title", HIR"呆哑喇嘛"NOR);
	set("gender", "男性" );
	set("age", 52);
	set("skill_public",1);
	set("int", 30);
	set("str", 30);
        create_family("大招寺", 33, "弟子");
	set("long",
		"赤松本是班禅大师的首徒,可是被人陷害,双足齐断,困于谷中.\n");
	set("chat_chance", 5);
        set("chat_msg", ({
                "赤松说道：谁能替我伸冤报仇,我愿将全身功夫相授!\n",
        }) );

	set("inquiry", ([
	"报仇"	 : "由此往南不远便是恶人谷,杀尽那里的恶人,就算为我复仇了.\n",
	"恶人谷" : (: ask_me :),
	"恶人"	 : (: ask_me :),
	"舍利子" : "真舍利子被恶人谷的人抢去,你要把它夺回来!\n",
	]) );
	set("attitude", "peaceful");
	set_skill("unarmed", 200);
	set_skill("bloodystrike", 200);
	set_skill("force", 200);
	set_skill("bolomiduo", 25);
	map_skill("force", "bolomiduo");
	map_skill("unarmed","bloodystrike");
	set("combat_exp", 900000);
        set("max_force",5000);
        set("force",5000);
	setup();
	carry_object(__DIR__"obj/redcloth")->wear();
}
//modify skills

string ask_me()
{
	object me;
	string str;
	me = this_player();
	str = "赤松上下打量了你一眼,";

	if(me->query("combat_exp") <= 500000) {
		str+="你觉得浑身不舒服起来.\n";
		tell_object(me, str);
		str= "你的功夫太差,还是别去送死了.\n";
		return str;
	}
	str+="你豪气陡生,露出无所畏惧的表情.\n";
	tell_object(me, str);
	str= "去吧!\n";
	environment(this_object())->open_passage();
	return str;
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/song") ){
                say("赤松咬牙切齿地说道: 杀....杀.....杀尽恶人.....\n");
                return 0;
        }
        return 1;
}

int accept_object(object who, object ob)
{
	int bonus;
        if(who->query("marks/song")==1){
               command("?");
               return 1;
        }
	if( ob->name() != "舍利子")
	{
		say("赤松说道：唉，我要的是舍利子....\n");
		return 1;
	}
	if (ob->query("nature")!= "real" )
        {
		say("赤松说道：唉，你也被那些人骗了，这舍利子是假的....\n");
                return 1;
        }
	else
	{
	who->set("marks/song", 1);
	say("赤松说道：好！好！好！太好了！我的冤终于见青天了....\n");
	bonus = (int) who->query("combat_exp");
        bonus += random(1000);
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential") - (int) who->query("learned_points");
        bonus += random(20)+20;
        bonus = (bonus>100? 100:bonus);
        who->set("potential", bonus + (int) who->query("learned_points"));
	return 1;	
	}
	return 1;
}
