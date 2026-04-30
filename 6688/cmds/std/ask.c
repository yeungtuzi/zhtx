// ask.c

#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int answer_string(object me, object asker, string msg);
int answer_sequence(object me, object asker, int count, mixed *msg);

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob,*usr;
	// 2026-04-30: unused variable commented out
	// mapping inquiry;
	int i;

	seteuid(getuid());                                                                    

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什麽事？\n");

	if( !objectp(ob = present(dest, environment(me)))
	||	!ob->is_character()
	||	!ob->query("can_speak") )
		return notify_fail("这里没有这个人。\n");                  

	if( ob==me )	return notify_fail("你为什么问自己？\n");

	// Let daemon do special asking message if asked special topic.
	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( !living(ob) ) {
		write("但是" + ob->name() + "现在的状况没有办法给你任何答覆。\n");
		return 1;
	}

	if( ob->is_busy() || ob->is_fighting() ) {
		write( ob->name() + "正忙著其他事，没空理你。\n");
		return 1;
	}                                                                     
  	if( sizeof(ob->query_temp("apply/name")) )
  	{
  		write(ob->name()+"现在不打算和人闲聊。\n");
  		return 1;
        }
	if( !userp(ob) ) 
	{
		if( msg = ob->query("inquiry/" + topic) ) {
			if( stringp(msg) )
				ob->start_busy( (: answer_string, ob, me, msg :) );
			else if( arrayp(msg) )
				ob->start_busy( (: answer_sequence, ob, me, 0, msg :) );
		} else
		ob->relay_ask(me, topic);             

		if( topic==ob->query("name") )
		{
			message_vision("$n哈哈大笑了几声，说道：\n", me, ob);
		               message_vision("「想不到$N这位"+RANK_D->query_respect(me) +
               			 "也知道"+RANK_D->query_self_close(ob)+"的名字。」\n", me);
		}      

		if( topic==ob->query("nickname") )
		{
			message_vision("$n哈哈大笑了几声，说道：\n", me, ob);
	               	message_vision("「这是江湖中朋友对"
				+RANK_D->query_self_close(ob)+"的称呼。」\n", me);
		}      
	}
                                                                                   
//	if( topic=="英文名字" )
//             message_vision(RANK_D->query_self(ob)+"的 id 是"+ob->query("id")+"。\n", me);
                                    
	if( topic=="名字" )
               	message_vision(RANK_D->query_self(ob)+"名叫"+ob->name()+"。\n", me);
                                                                      
	if( topic==ob->query("wife/id") || topic==ob->query("wife/name"))
	{		
		if( topic==me->query("id") || topic==me->name() )
			message_vision("$n说道:「你是我的妻子，你难道忘了？」\n",me,ob);
		else	message_vision("$n说道：「她是我的妻子，你问这干吗？」\n", me ,ob);
	}

	if( topic==ob->query("husband/id") || topic==ob->query("husband/name"))
	{
		if( topic==me->query("id") || topic==me->name() )
			message_vision("$n说道:「你是我的丈夫，你难道忘了？」\n",me,ob);
		else	message_vision("$n说道：「他是我的丈夫，你问这干吗？」\n", me ,ob);
	}
                                                           
	if( topic==ob->query("mother/id") || topic==ob->query("mother/name"))
		message_vision("$n说道：「她是我的母亲，你见到她老人家了吗？」\n", me ,ob);

	if( topic==ob->query("father/id") || topic==ob->query("father/name"))
		message_vision("$n说道：「他是我的父亲，你见到她老人家了吗？」\n", me ,ob);

	if( topic==me->query("wife/id") || topic==me->query("wife/name"))
	{
		if( topic==ob->query("id") || topic==ob->name() )
			message_vision("$n说道:「我是你的妻子，你难道忘了？」\n",me,ob);
		else	message_vision("$n说道：「她是你的妻子，你难道忘啦吗？」\n", me ,ob);
	}

	if( topic==me->query("husband/id") || topic==me->query("husband/name"))
	{
		if( topic==ob->query("id") || topic==ob->name() )
			message_vision("$n说道:「我是你的妻子，你难道忘了？」\n",me,ob);
		else	message_vision("$n说道：「他是你的丈夫，你难道忘啦吗？」\n", me ,ob);
	}

	usr=users();          

	for(i=0;i<sizeof(usr);i++)
	{                          
		if( topic==usr[i]->query("name") )
		{                    
			if( usr[i]!=me )
			{
				if( usr[i]==ob )      
				{
					message_vision("$n哈哈大笑了几声，说道：\n", me, ob);
               				message_vision("「这是"
						+RANK_D->query_self_close(ob)+"的名字。」\n", me);
				}
				else
				{              
					message_vision("$n说道：「有一位玩家叫这个名字，", me, ob);
					if( usr[i]->query("gender")=="女性" )
						message_vision("她是"+usr[i]->query("title")+"。」\n", me, ob);
					else
						message_vision("他是"+usr[i]->query("title")+"。」\n", me, ob);		
				}
			}
			else
				message_vision("$n说道：「这不是"+
						RANK_D->query_respect(me)+"你的名字吗？」\n", me, ob);

		}
		if( topic+NOR==usr[i]->query("nickname") )
		{                    
			if( usr[i]!=me )
			{
				if( usr[i]==ob )      
				{
					message_vision("$n哈哈大笑了几声，说道：\n", me, ob);
               				message_vision("「这是江湖中朋友对"
						+RANK_D->query_self_close(ob)+"的称呼。」\n", me);
				}
				else
				{
               				message_vision("「这是江湖中朋友对"
						+usr[i]->query("name")+"的称呼。」\n", me);
				}
			}
			else
				message_vision("$n说道：「这不是江湖中朋友对"+
						RANK_D->query_respect(me)+"你的称呼吗？」\n", me, ob);
		}
	}

	return 1;
}

int answer_string(object me, object asker, string msg)
{
	if( environment(me) != environment(asker) ) return 0;
	SAY_CMD->main(me, msg);
	return 0;
}

int answer_sequence(object me, object asker, int counter, mixed *msg)
{
	if( environment(me) != environment(asker) ) return 0;
	if( sizeof(msg) <= counter ) return 0;

	if( stringp(msg[counter]) )
		SAY_CMD->main(me, msg[counter]);
	else if( functionp(msg[counter]) ) {
		me->set_temp("last_asker", asker);
		evaluate(msg[counter]);
	}

	me->start_busy( (: answer_sequence, me, asker, counter + 1, msg :) );
	return 1;	
}

int help(object me)
{
   write( @HELP
指令格式: ask <某人> about <关键字>

询问其他人物有关某关键字的讯息。

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
