//zephyr revised for weaponor riddle               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;
void ask_me();
void ask_wood();

void create()
{
        set_name("孔长生", ({ "kong changsheng" , "kong" , "changsheng" }));
        set("title",GRN"木器店老板"NOR);
        set("long",
        "孔记木器店的老板，他有一双天下无双的巧手，做出来的木器真是神乎其技。在京城\n"
        "也算小有名气的人物，无数人慕名而来仅仅是为了求他做件竹椅。\n");
        set("gender", "男性");
        set("age", 43);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("count",1);
        set("dex", 25);
        set("combat_exp", 10000);
        set_skill("dodge", 20);
        set_skill("unarmed", 50);
        set_temp("apply/defense", 10);

		          set("inquiry",([
                "修木器"    : (: ask_me :),
                "修木刀"    : (: ask_me :),
                "修木头"    : (: ask_me :),
                "修刀"    : (: ask_me :),
                "修补"    : (: ask_me :),
                "修理"    : (: ask_me :),
                "维修"    : (: ask_me :),
                "找杨树"    : (: ask_wood :),
                "黄杨木"    : (: ask_wood :),
                "杨树"    : (: ask_wood :),
                "杨树树种"    : (: ask_wood :),
                "树种"    : (: ask_wood :),
                "找树种"    : (: ask_wood :),
                "找"    : (: ask_wood :),
        ]));

        set("vendor_goods", ([
           "/d/jingcheng/npc/obj/muding":10,
           "/d/jingcheng/npc/obj/muyi":10,
           ]));
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "孔长生轻轻一笑说：多谢大家捧场。\n",   
        }) );
        carry_object("/obj/cloth/cloth")->wear();
}
void init()
{
        object me;
        ::init();
         add_action("do_vendor_list","list");
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}
void greeting(object me)
{
        command("say "+RANK_D->query_respect(me)+"四处看看，对什么东西有兴趣。\n");
}

void ask_me()
{
        object blade, po_blade;
        if (!query("count")) return;
        command("smile");
        command("say 老夫修木头玩意的手艺还过得去。");
		po_blade = present( "po chubi dao",this_player() );
		if ( objectp(po_blade) )
		{
			po_blade->move(this_object());
			message_vision("\n$N双手捧上木刀，恭恭敬敬地道：可否请你帮我修补这把木刀\n",environment());
			message_vision("\n"+name()+"接过木刀，仔细端详了良久，缓缓道：此刀乃是一种奇特的黄杨木雕成\n",environment());
			command("say 老夫从未见过此种木料。这...");
			command("hmm");
			command("say 除非能找到这种黄杨木树种，取其树髓精华，合其树脂之精，才可能修补此刀。");
			this_player()->set_temp("find_wood",1);
		}
        return;
}

void ask_wood()
{
        object saw;
		saw = new(__DIR__"saw");
        if (!this_player()->query_temp("weaponor5")) return;
        if (!this_player()->query_temp("find_wood")) return;
        
		command("hmm");
        command("say 天下之大，要找到此种奇木的确很难啊！");
        command("hmm");
        command("say 这样吧，我这里有一把锯子，锋利异常，你四处去找找看哪儿有杨树，找到合适的木头以后，拿回来我看看能不能用吧！");
        switch (random(9))
        {
        case 0: saw->set("location","/d/quanzhen/mingmu");
				break;
        case 1: saw->set("location","/d/heimuya/yidao1");
				break;
        case 2: saw->set("location","/d/suzhou/szroad2");
				break;
        case 3: saw->set("location","/d/suzhou/szroad3");
				break;
        case 4: saw->set("location","/d/suzhou/szroad4");
				break;
        case 5: saw->set("location","/d/suzhou/szroad6");
				break;
        case 6: saw->set("location","/d/suzhou/szroad7");
				break;
        case 7: saw->set("location","/d/suzhou/szroad8");
				break;
        case 8: saw->set("location","/d/suzhou/szroad9");
				break;
        }
		saw->move(this_player());
		this_player()->delete_temp("find_wood");
		this_player()->set_temp("chop_wood",1);

		return;
}


int accept_object(object ob, object obj)
{
	object blade, po_blade;
	if (!ob->query_temp("weaponor5"))
	{
		command("say 你我素昧平生，为何要送我此物？\n");
		return 0;
	}

	if (!ob->query_temp("chop_wood"))
	{
		command("say 无功不受禄，这木料我可不能要。");
		return 0;
	}

	if ((obj->query("id")=="yang shu") && ob->query_temp("chop_wood") )
	{
		po_blade = present( "po chubi dao",this_object() );
		this_player()->delete_temp("chop_wood");
		command("say 哎呀，你真是有缘人，这正是一棵千古奇木啊。\n");
		command("say 请少待。\n");
        message_vision("\n孔长生回到屋里乒乒乓乓一阵.......\n",environment());
        message_vision("\n许久，孔长生手持一柄黄颜色的弯刀出来，交给了$N。\n",environment());
        message_vision("\n$N仔细一看，大喜：正是出跸刀啊！\n",environment());
        message_vision("\n$N手持弯刀，连连称谢。\n",environment());
		command("say 不必谢我，这事主要是你的缘分。那树还剩下了一大段木料，如果你没有其他用处，就留给老夫，可好？\n");
        message_vision("\n$N连忙点头道：自然自然。\n",environment());
        blade=new(__DIR__"chubiblade2");
        blade->move(this_player());
		if (objectp(po_blade))
			destruct(po_blade);
		destruct(obj);
		return 1;
	}
	if ((obj->query("id")=="yang wood") && present("po chubi dao",this_object()) )
	{
		command("say 这只是一段平平常常的木头而已，没什么稀奇。\n");
		command("say 再四处找找看吧。\n");
		destruct(obj);
		return 1;
	}
}
