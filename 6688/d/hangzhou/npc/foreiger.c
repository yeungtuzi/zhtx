//modified by tlang

#include <ansi.h>
inherit NPC;
#include "/d/hangzhou/npc/desc.h"

void create()
{
	set_name(YEL"西欧游客"NOR, ({ "foreiger","outer"}) );
	set("age", 25+random(4));
        set("long","这是一位到杭州旅游的外国游客。\n");

	set("attitude", "friendly");
	
	setup();
	add_money("gold",1);   
	carry_object(__DIR__"obj/xifu.c")->wear(); 
	carry_object(__DIR__"obj/camera")->wield();
}

void init()
{
	object ob=this_player();

	remove_call_out("greeting");
	call_out("greeting",1,ob);
}

int greeting(object ob)
{
	object me, obj, pic, env;
        int i;
        string str, objname, objid, pro;
        mixed *inv;
        // 2026-04-30: unused variable commented out
        // mapping exits;

        me = this_object();
	obj=ob;
		
	if( !ob || environment(ob) != environment() ) return 0;
	if(objectp(present("photo",ob) ) )
	{
		command("smile "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)+"我拍的照片还行吧？\n");
		return 1;
	}
	         
	switch(random(2))
	{
	case 0: 
       	        env = environment(me);
                str = objname = env->query("short");
                if( !env ) str = "照片上灰蒙蒙地一片，不知道是本来就是这样还是冲坏了。\n";
                else
                {
                        str = sprintf( "%s的照片\n\n    %s%s\n",env->query("short"), env->query("long"),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
                       
                        inv = all_inventory(env);
                        for(i=0; i<sizeof(inv); i++) {
                                if( inv[i]==me ) continue;
                                if ( inv[i]->is_character() )
                                {
                                        if( !me->visible(inv[i]) ) str += "  " + BLU + inv[i]->name() + NOR;
                                        else str += "  " + inv[i]->name();

                                        str += msg_expression[random(EXP_NUM)] + "\n";
                                }
                                else str += YEL+"  [ " + inv[i]->name() +" ]\n" +NOR;
                        }
                }

                str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
                message_vision("$N轻轻按下了快门…" HIY
                                "\n伴随着一道眩目的亮光和咔嚓一声响……\n$N拍下了一张照片！！\n" NOR, me);

                pic=new("/d/hangzhou/npc/obj/photo.c");
                pic->set_name( objname + "的照片", ({ "photo" }) );
                pic->set("long", str);
                pic->move(ob); 
               	command("say "+RANK_D->query_respect(ob)+"我拍了几张照片，送给你吧。。。\n");
	break;
    	case 1:
	       
        objname = obj->query("name");
        objid = obj->query("id");
        str = objname+"的照片\n\n";

        switch (random(6))
       	{
	        case 0:
        	        str="一张严重曝光过度的照片，好一个“白茫茫一片大地真干净”。\n";
                	str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
        	break;
        	case 1:
          	     str="一张严重曝光不足的照片，角落里隐隐约约写着“黑夜里乌鸦在飞”。\n";
           	     str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
      		break;
      		case 2:
        	case 3:
        	case 4:
        	case 5:
                	str += obj->name() + msg_expression[random(EXP_NUM)] + "\n";
                	str += obj->long();
	                pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	                if( (string)obj->query("race")=="人类"
        	        &&      intp(obj->query("age")) )
                	        str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(obj->query("age") / 10 * 10));

	                str += pro + per_status_msg((int)obj->query("per"), obj->query("gender"));
	
        	        inv = all_inventory(obj);
                	if( sizeof(inv) ) {
                        	inv = map_array(inv, "i_look", this_object(), obj->is_corpse()? 0 : 1 );
                        	inv -= ({ 0 });
                        	if( sizeof(inv) )
                                	str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                          	              pro, implode(inv, "\n") );
                	}
                	str += "\n" + me->query("name")+"摄于"+NATURE_D->game_time() + "。\n";
         	       break;
		}

 	       message_vision("$N轻轻按下了快门……"+HIY+"\n伴随着一道眩目的亮光和咔嚓一声响，\n"
                       "$n突然觉得身子轻飘飘地，脑袋里空空荡荡，好象魂已经出窍了！\n" NOR,me, obj);

	        pic=new("/d/hangzhou/npc/obj/photo.c");
        	pic->set_name( objname + "的照片", ({ objid+" photo", "photo" }) );
        	pic->set("long", str);

 	       pic->move(ob);
	       command("say "+RANK_D->query_respect(ob)+"我拍了几张照片，送给你吧。。。\n");
	  break;
	 }
}
