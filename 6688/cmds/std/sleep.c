// sleep.c
// www
// last updated 3/27/97

void wakeup(object,object);

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);
	

        seteuid(getuid());

	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("这里不是你能睡的地方！\n");
   
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能睡觉！\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n",me);
		return 1;
	}
 
	if(me->query_condition("sleep"))
		return notify_fail("你刚在五分钟内睡过一觉, 多睡对身体有害无益! \n");

	if (where->query("sleep_room"))
	{
		write("你往床上一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
	}
	else { 
		write("你往地下角落一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",me);
	}
		if( where->query("no_fight")  ) {
			where->set_temp("no_fight",1);
		}   
		else	where->set("no_fight", 1);
	where->add_temp("sleeping_person", 1);

	me->set("no_get", 1);	
	me->set("no_get_from", 1);	
/*	
	if (!(where->query("hotel"))) 
		me->apply_condition("sleep", 10);
	else
		me->delete_temp("rent_paid");
*/
	me->apply_condition("sleep", 10);

	me->disable_player("<睡梦中>");

	call_out("wakeup",random(45 - me->query("con")) + 1, me, where);
        
	return 1;
	
}

void wakeup(object me,object where)
{
	me->set("kee",    me->query("eff_kee"));
	me->set("gin",  me->query("eff_gin"));
        me->set("sen",  me->query("eff_sen"));
	if( (me->query("max_force")/2 - me->query("force")/2) > 0 )
		me->add("force", me->query("max_force")/2 - me->query("force")/2 );
	me->enable_player();
  

	message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
	me->set_temp("block_msg/all", 0);
        /*  call move to re init all actions dao 971216 */
        {
                object * inv;
                int i;

        me->move(where);
        inv = all_inventory(me);
                i = sizeof(inv);
                while(i--) {
                        string status=inv[i]->query("equipped") ;
                        inv[i]->move(me);
                        if( status == "worn" ) inv[i]->wear();
//                        else if (status == "wielded") inv[i]->wield();
                }
        }

	write("你一觉醒来，只觉精力充沛。该活动一下了。\n");

	if (!where->query("sleep_room") && !where->query("hotel")) {
	    if( !where->query_temp("no_fight"))
		where->delete("no_fight");
	    else 
		where->delete_temp("no_fight");
	}
     
	where->add_temp("sleeping_person", -1);
	me->delete("no_get");	
	me->delete("no_get_from");	
 
}

