//made by tlang
//yanhua.c
              
#include <ansi.h>
#include <weapon.h>
inherit ITEM;

void create()
{
        switch(random(5))
        {
                case 0:
                        set_name(RED"心连心"NOR, ({"heart&heart fire","fire"}));
                        break;
                case 1 :
                        set_name(GRN"满天飞"NOR, ({"flying-in-sky fire","fire"}));
                       break;
                case 2 :
                        set_name(YEL"新年快乐"NOR, ({"happy-new-year fire","fire"}));
                        break;
                case 3 :
                        set_name(HIC"万事如意"NOR, ({"all-go-well fire","fire"}));
                        break;
                case 4 :
                        set_name(HIM"新婚快乐"NOR, ({"happy-marry fire","fire"}));
                        break;
               }

        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 1000);
                set("material", "steel");
            //    set("wield_msg", "$N急急忙忙地拿出一支$n。\n");
            //    set("unwield_msg", "$N将手中的$n放回包里。\n");
        }
//        init_hammer(5);
        setup();
}

void init()
{
                add_action("do_shoot","shoot");
}

int do_shoot()
{
        object me, ob, env;
        me=this_player();
	ob=this_object();
	
	if(!me->query("gin")>=10)
		return notify_fail("你现在哪有精神放烟花啊！\n");
  	env = environment(me);
	if (ob->query("id")=="heart&heart fire")
	{
        tell_room(env,"一位"+RANK_D->query_respect(me)+"轻轻点燃一支烟花…\n"
 HIM"伴随着一道眩目的亮光和嗖的一声响……一道烟花直冲上天！！\n"
"									\n"
"		       /|\	/|\					\n"
"		      /    \ /	    \					\n"
"		/____|_____ _|_______|___________________		\n"					
"		\    \ 	    / \	     /					\n"
"		       \___/   \____/					\n"
"									\n"
"									\n"NOR);
	destruct(ob);
		return 1;
	}
	if(ob->query("id")=="flying-in-sky fire")
	{
	tell_room(env,"一位"+RANK_D->query_respect(me)+"轻轻点燃一支烟花…\n"
 YEL"伴随着一道眩目的亮光和嗖的一声响……一道烟花直冲上天！！\n"
"									\n"
"	**	 * *	  *		**	*      **	*	\n"
"	*   *  *   *	*    *		*  *	*     *	      *		\n"
"	*   *  *   *	*    *		*  *	*     	*     *		\n"					
"	*   *  *   *	*    * 		**	*      **	*	\n"
"	**	 * * 	  *						\n"
"									\n"NOR);
	destruct(ob);
		return 1;
	}
	if(ob->query("id")=="happy-new-year fire")
	{
	tell_room(env, "一位"+RANK_D->query_respect(me)+"轻轻点燃一支烟花…\n"
 RED"伴随着一道眩目的亮光和嗖的一声响……一道烟花直冲上天！！\n"
"		*   *    *    ***   ***    *     * 			\n"
"		*   *         *  *  *	*    * *			\n"
"		*   *	* *   *  *  *	*     *  			\n"
"		*****	      ***   ***       *				\n"					
"		*   *  *****  *     *	      *				\n"
"		*   *	      *     *	      *				\n"
"		*   *  *   *  *     *	      *				\n"
"		*   *  *   *  *     *	      *				\n"
"*   *	*****  *   *   *       *     *	*****	  *	*****		\n"
"*   *	*			*   *	*	 	*   *		\n"
"**  *  *       *  *  *	       	  *	*	 * *	*   *		\n"
"*   *	*			  *	*		*****		\n"					
"* * * 	*****	 * * * 		  *	*****	*****	* *  		\n"
"*   *	*	      		  *	*		*  *		\n"
"*  **	*			  *	*	*   *	*   *		\n"
"*   *	*****	  * *		  *	*****	*   *	*   *		\n"NOR);
	destruct(ob);
		return 1;
	}
	if(ob->query("id")=="happy-marry fire")
	{
	tell_room(env, "一位"+RANK_D->query_respect(me)+"轻轻点燃一支烟花…\n"
 MAG"伴随着一道眩目的亮光和嗖的一声响……一道烟花直冲上天！！\n"
"		*   *    *    ***   ***    *     * 			\n"
"		*   *         *  *  *	*    * *			\n"
"		*   *	* *   *  *  *	*     *  			\n"
"		*****	      ***   ***       *				\n"					
"		*   *  *****  *     *	      *				\n"
"		*   *	      *     *	      *				\n"
"		*   *  *   *  *     *	      *				\n"
"		*   *  *   *  *     *	      *				\n"
"		   * *	    *	*****	*****	*     *			\n"
"		   	  	*   *	*   * 	  * * 			\n"
"		  * * *    * * 	*****	*****	   *			\n"
"				* *  	* *	   *			\n"					
"		 *  *  *  ***** *  *	*  * 	   *			\n"
"		      	  *   *	*   *	*   *	   *			\n"
"		*   *   * *   *	*   *	*   *	   *			\n"
"									\n"NOR);
	destruct(ob);
		return 1;
	}
	if(ob->query("id")=="all-go-well fire")
	{
	tell_room(env, "一位"+RANK_D->query_respect(me)+"轻轻点燃一支烟花…\n"
 GRN"伴随着一道眩目的亮光和嗖的一声响……一道烟花直冲上天！！\n"
"	&&	&&	&&  	&&&&&&&&&&	&		&	\n"
"		 		&		&		&	\n"
"	 &&    &&&&    &&	&		&		&	\n"
"		 		&&&&&&&&&&	&		&	\n"					
"	  &&  &&  &&  &&	&		&		&	\n"
"		      		&		&		&	\n"
"	   &&&&	   &&&&		&		&		&	\n"
"	    &&	    &&		&&&&&&&&&&	&&&&&&&&&	&&&&&&&&&\n"NOR);
	destruct(ob);
		return 1;
	}
}

