// BLUGIRL.C
#include <ansi.h>

inherit NPC;

string tell_test();

void create()
{       
        object armor;
        set_name(BLU "蓝衣少女" NOR, ({ "blue girl","girl" }) );
        set("long", "她身穿轻纱柔丝，白足如霜，蓝丝飘扬。\n");
        set("age", 16);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", random(500000));  
        set("kee", 3000);
        set("eff_kee", 3000);
        set("max_kee", 3000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "\n",
        }) );

        set("inquiry", ([
                "嫁衣神功":(: tell_test:),
	        "jiayiforce" : (: tell_test :)
        ]) );
	
        setup();
        armor=new(__DIR__"obj/corclot");
        armor->set_name(BLU "蓝衣" NOR,({"blue cloth","cloth"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corclasp");
        armor->set_name(BLU "蓝镯" NOR,({"blue bangle","bangle"}) );
        armor->move(this_object());
        armor->wear();  
        armor=new(__DIR__"obj/corgirt");
        armor->set_name(BLU "蓝带" NOR,({"blue belt","belt"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corhat");
        armor->set_name(BLU "蓝帽" NOR,({"blue hat","hat"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corboot");
        armor->set_name(BLU "蓝鞋" NOR,({"blue boot","boot"}) );
        armor->move(this_object());
        armor->wear();
        armor=new(__DIR__"obj/corribb");
        armor->set_name(BLU "蓝巾" NOR,({"blue ribbon","ribbon"}) );
        armor->move(this_object());
        armor->wear();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
   mixed foo;
   object *inv;
   object dress; 
   int i; 
   //foo = ::hit_ob(me,victim,damage_bonus);
     if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
              //message_vision(YEL "$n身上的"+dress->name()+"被$N脱了下来。\n" NOR,me,victim);
              dress->move(environment());
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "身上的"+dress->name()+"被$N脱了下来。\n" NOR;
           } 
          };

            
           
        return;
}

string tell_test()
{
	object me,book;

	me = this_player();

	if( me->query("family/family_name") != "铁血大旗门" )
		return "你不是我派门人，给了你会被公子责骂的。";
	if( me->query_per() < 25 )
	{
		message_vision("$N对$n摇了摇头，转过身去。\n",this_object(),me);
		return "我对你没有兴趣耶。";
	}

	if( me->query_skill("jiayiforce",1) < 55 )
	{
		command("shake");
		return "你功夫不够，强自修炼会害了你的，你先回去吧。";
	}

	book = new(__DIR__"obj/jiabook2");
	book->move(me);

	command("blush "+me->query("id"));	
	return "公子给了我一本书让我保管，我先借你看看，不要告诉别人喔";
}


