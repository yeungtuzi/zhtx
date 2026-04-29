// unique.c

// This function returns 1 if this_object() is not the unique clone in
// the mud. Note that calling this function on master copy always 
// return 0.
nomask int violate_unique()
{
	object *obs,env;
	int i;

	if( !clonep(this_object()) ) return 0;

	// Find all the cloned instance of this_object()
	// 采取另外一种UNIQUE的方式,到刷新的时候,Unique的东西
	// 要回到原先主人的手里.
	obs = filter_array( children(base_name(this_object())), 
	                    (: clonep :) );
 	i = sizeof(obs);
 	// 物品可以设定最大允许的数量,比如不是那么珍贵的可以设置成
 	// 线上只允许存在10个等等.
 	// 相应的属性是set("unique_limit",10),缺省是只允许存在一个.
 	// 其他的全部收缴.
         if( i > (int)this_object()->query("unique_limit") )
 	while( i-- )
 	{
 		if( obs[i]!=this_object() 
 		    && objectp(env=environment(obs[i])) )
 		{                                                  
 			if( env->is_character() )
 				tell_object(env,"你的"+obs[i]->name()
 				    +"化作一阵轻烟,消失的无影无踪.\n");
 			else
 				tell_room(env,obs[i]->name()
 				    +"化作一阵轻烟,消失的无影无踪.\n");			
 			destruct(obs[i]);
 		}
 	}	

	return 0;
}

// This function returns the replica of this_object() if any.
object create_replica()
{
	string replica;
	object obj;

	seteuid(getuid());
	if( stringp(replica = this_object()->query("replica_ob")) )
		obj = new(replica);
	else
		obj = 0;
	destruct(this_object());
	return obj;
}
