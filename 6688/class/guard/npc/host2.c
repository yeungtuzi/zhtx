//hostress2
//by tlang with /class/guard/npc/host.c

#include <ansi.h>

inherit NPC;

void heal();
void init();
int do_dian(string arg);
int checking();
int dest();
int accept_object(object,object); 


string *start_loc = ({
        "/d/snow/inn",
        "/d/guanwai/inn",
        "/d/cloud/tearoom",
        "/d/jingcheng/jiuguan",
        "/d/yueyang/kedian",
	"/d/suzhou/kezhan",
});

void create()
{
	set_name(GRN"雪儿"NOR, ({ "xue er", "xue"}) );
	set("gender", "女性" );
	set("age", 18);
        set("long",
		"她是天下文明的烹调高手，据说出师于杭州三雅园。\n");
	set("combat_exp", 2999999);
	set("attitude", "peacefully");
	set("per", 30);
	set("int", 30);
	set("con", 30);
	set("str", 20);
	set("cps", 30);
	     
	set("max_kee", 3000);
	set("kee", 3000);   
	set("max_atman",3000);
	set("atman",3000);
	set("max_force", 3000);
	set("force", 5000);
	set("force_factor", 200);
	set("max_mana",3000);
	set("mana",5000);
	set("mana_factor", 50);
	
	set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
//		(: random_move :),
        }));	

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "invocation" :),
                (: command("cast animate on corpse") :),
                (: command("cast animate on corpse") :),
        }) );
		
	set_skill("iron-cloth", 200);
	set_skill("dodge", 220);
	set_skill("unarmed", 200);
	set_skill("spells",200);
	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("taoism", 220);
        set_skill("necromancy", 200);
	map_skill("force", "taiji-shengong");
	map_skill("spells","necromancy");

	setup();
	carry_object("/d/suzhou/npc/obj/cloth2.c")->wear();
	call_out("checking",600);
}  

void init()
{
	add_action("do_dian","dian");
}

int do_dian(string arg)
{
	object ob,obj1,obj2;
		
	ob=this_player();
	
	if(!arg || arg=="")
		return notify_fail("你要什么菜呢？我能做:\n
			1.糖醋鱼(fish)
			2.五香鸡翅(chicken)。。。。\n");
	if(this_object()->is_busy())
		return notify_fail("对不起，稍等一会儿。\n");
	if(arg=="fish")
	{
		obj1=new("/class/guard/npc/obj/fish");	
		command("smile");
		tell_room(environment(ob),"只见雪儿飞快地行动起来，不一会儿
就做好了。把它交给了"+RANK_D->query_respect(ob)+".\n");	
		obj1->move(ob);
		this_object()->start_busy(2);
			return 1;
	}
	if(arg=="chicken")
	{
		obj2=new("/class/guard/npc/obj/chicken");
		command("smile");
		tell_room(environment(ob),"只见雪儿飞快地行动起来，不一会儿
就做好了。把它交给了"+RANK_D->query_respect(ob)+".\n");
		obj2->move(ob);	
		this_object()->start_busy(2);
			return 1;
	}
}

int checking()
{
	object *ob;
        int i;
	string startroom;	

	ob = users();
	command("say 大家过完节，也该散了。\n");
	for(i=0; i<sizeof(ob); i++) {
	        if( !ob[i] || environment(ob[i]) != environment() ) continue;
	startroom = start_loc[random(sizeof(start_loc))];  
	ob[i]->move(startroom);     			
	}
	command("sigh");
	call_out("dest",120);
}

int dest()
{
	command("smile");
	destruct(this_object());
}

int accept_object(object who, object what)
{                              
        command("say 是你给我东东吗？谢谢了。");
        command("thank " + who->query("id") );
        destruct(what);
	        return 1;
}

void heal()
{
        object ob=this_object();

        if (ob->query("eff_kee") < ob->query("max_kee"))
        {
                command("exert heal");
                command("enforce 20");
                return;
        }

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}
