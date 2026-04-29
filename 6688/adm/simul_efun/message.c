//      /adm/simul_efun/message.c
// message.c
#include <ansi.h>


//this function changed by yeung to add 3rd char surpport and to avoid pleonasticly messages 
//when one of (me,you and him) is same to another.

varargs void message_vision(string msg, object me, object you,object him)
{
	string my_gender, your_gender, his_gender,my_name, your_name,his_name;
	string str1, str2, str3,str4;
	object *ob;
	object env;
        int i;
	
	my_name= (string)me->name();
	if(!my_name) my_name="";
	my_gender = (string)me->query("gender");

// this part added -----------------
	if( him == you)
	{
		msg = replace_string(msg,  "$K","$p");
		msg = replace_string(msg,  "$k","$n");
		him = 0;
	}
	else if( him == me)
	{
		msg = replace_string(msg,  "$K","$P");
		msg = replace_string(msg,  "$k","$N");
		him = 0;
	}

	if( me == you)
	{
		msg = replace_string(msg,  "$p","$P");
		msg = replace_string(msg,  "$n","$N");
		you = 0;
	}
// end ------------------------------

	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= (string)you->name();
		your_gender= (string)you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));

		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
// begin -----------------------------
	if( him ) {
		his_name= him->name();
		his_gender= him->query("gender");
		str4 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str4 = replace_string(str4, "$p", gender_pronoun(your_gender));
		str4 = replace_string(str4, "$K", gender_self(his_gender));
		str4 = replace_string(str4, "$N", my_name);
		str4 = replace_string(str4, "$n", your_name);
		str4 = replace_string(str4, "$k", gender_self(his_gender));

		str1 = replace_string(str1, "$K", gender_pronoun(his_gender));
		str1 = replace_string(str1, "$k", his_name);
		str2 = replace_string(str2, "$K", gender_pronoun(his_gender));
		str2 = replace_string(str2, "$k", his_name);
		str3 = replace_string(str3, "$K", his_name);
		str3 = replace_string(str3, "$k", his_name);
	}
// end --------------------------------

// changed
	if( me && !(int)me->query("env/message_brief"))
		 message("vision", str1, me);

// moved to here
	if( you && !(int)you->query("env/message_brief"))
		 message("vision", str2, you);
	
// added
	if( him && !(int)him->query("env/message_brief"))
		 message("vision", str4, him);

	env = environment(me);
	if(!env) return;
	ob=all_inventory(env);
	i=sizeof(ob);
	while(i--)
	{
//changed
		if(ob[i]!=me && ob[i]!=you && ob[i]!=him)
		{
			if(!(int)ob[i]->query("env/others_message_brief"))
				message("vision", str3, ob[i]);
		}
	}
//	message("vision", str3,  environment(me), ({ me, you}) );
}

varargs void message_combat(int priority,string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;
	string *watchroom;
	object *ob,room;
        int cmsg,i;
        mixed cmsgst;

	my_name= me->name();
	my_gender = me->query("gender");

// added --
	if( me == you)
	{
		msg = replace_string(msg,  "$p","$P");
		msg = replace_string(msg,  "$n","$N");
		you = 0;
	}
// end ----

	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
                
                cmsgst=you->query("env/combat_brief");
                if (intp(cmsgst)) cmsg=cmsgst; else cmsg=0;
                if (cmsg<priority) 
                     message("combat", str2, you);
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
        cmsgst=me->query("env/combat_brief");
        if (intp(cmsgst)) cmsg=cmsgst; else cmsg=0;
        if (cmsg<priority) 
		message("combat", str1, me);

	ob=all_inventory(environment(me));
	i=sizeof(ob);
	while(i--)
	{
		if(ob[i]!=me && ob[i]!=you)
		{
			cmsgst=ob[i]->query("env/others_combat_brief");
		        if (intp(cmsgst)) cmsg=cmsgst; else cmsg=0;
	        	if (cmsg<priority) 
				message("combat", str3, ob[i]);
		}
	}
			
//	message("combat", str3,  environment(me), ({ me, you}) );

	if( arrayp(watchroom=environment(me)->query("watch_room"))
		&& (i=sizeof(watchroom)) )
	{
		while(i--)
			if( room=find_object(watchroom[i]) )
				message("combat", str3,  room );
	}
}

void tell_object(object ob, string str)
{
	message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
	message("shout", str, users(), this_player());
}

void write(string str)
{
	object ob;

	if( (ob=this_player()) )
		message("write", str, ob);
	else if( (ob=previous_object()) )
		message("write", str, ob);
	else
		efun::write(str);
}

varargs void say(string str, mixed exclude)
{
	if( living(previous_object()) )
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}

