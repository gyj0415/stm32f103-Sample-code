//
// Created by guan on 2025/5/21.
//
#include "app_music.h"

#include "app_system.h"
#include "bsp_buzzer.h"
#include "cmsis_os2.h"

/**
  * @brief				蜂鸣器和LED任务
  * @param[out]		不同频率及相应节拍
  * @param[in]		note音符，long音长
  * @retval
*/
void Note(int note,float Long)
{
	bsp_buzzer_flash(note, 0.02, Long*200);
}

/********** 《你》-GALA**********/
void gala_you(void)
{
	float t=0.2;

	Note( note_5B , 1 );    //前奏
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B ,  2);
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_5B , 1 );
	Note( note_5C , 1 );

	Note( note_5B , 1 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B ,  2);
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_5B , 1 );
	Note( note_5C , 1 );

	Note( note_5B , 1 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B ,  2);
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_5B , 1 );
	Note( note_5C , 1 );

  Note( note_5B , 1 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_D , 2 );

	Note( note_E , 6 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );

	Note( note_5C , 4 );
	Note( note_5B , 4 );
	Note( note_E , 4 );
	Note( note_D , 2 );

	Note( note_E , 6 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 8 );

	Note( note_5B , 2 );
	Note( note_5D , 4 );
	Note( note_E , 10 );

	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5B , 4 );

	Note( note_5C , 4 );
	Note( note_5B , 4 );
	Note( note_E , 4 );
	Note( note_D , 2 );

	Note( note_E , 6 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5B , 4 );

	Note( note_5C , 4 );
	Note( note_5D , 10 );

	Note( 0 , 4 );      //我一直追寻着你
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );

	Note( 0 , 2 );      //你好像不远也不近
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_C , 6 );

	Note( 0 , 2 );      //却总保持着距离
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
//	Note( note_D , 2 );
	Note( note_D , 2 );
//	Note( note_C , 1 );
	Note( note_C , 2 );
	Note( note_D , 2 );

	Note( 0 , 2 );
	Note( note_E , 2 );  //我一直幻想着你
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );

	Note( 0 , 2 );      //在我身边在我怀里
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_C , 6 );

	Note( 0 , 2 );      //让我欢笑让我哭泣
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_B , 2 );
	Note( note_A , 1 );
	Note( note_3G , 5 );

	Note( 0 , 1 );      //你是我灵魂的旋律
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( note_G , 4 );
	Note( note_E , 3 );
	Note( note_D , 1 );
	Note( note_C , 2 );
	Note( 0 , t );
	Note( note_C , 4 );

	Note( 0 , 1 );
	Note( note_C , 2 );      //春日的细雨
	Note( 0 , 0.05 );
	Note( note_C , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_A , 6 );

	Note( 0 , 2 );          //墓碑的雏菊
	Note( note_A , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_C , 2 );
	Note( note_D , 6 );
	Note( 0 , 2 );

	Note( note_E , 4 );      //我从来不会计算代价
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //为了你可以纵身无底悬崖
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 4 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_G , 1 );
	Note( 0 , 0.1 );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_G , 4 );
	Note( note_D , 8 );

	Note( note_E , 4 );     //像条狗更像一个笑话
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //也许我很傻但我不会怕
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5B , 4 );
	Note( note_5A , 6 );
	Note( 0 , t );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );

	Note( 0 , 2 );
	Note( note_G , 2 );   //我愿意呀
	Note( note_5C , 2 );
	Note( note_5B , 1 );
	Note( note_5C , 12 );

	Note( 0 , 4 );

  Note( 0 , 2 );      //人们都追寻着你
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );

	Note( 0 , 2 );      //都曾把你当作唯一
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_C , 6 );

//	Note( 0 , 4 );

	Note( 0 , 2 );      //最后却无能为力
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
//	Note( note_D , 2 );
	Note( note_D , 2 );
//	Note( note_C , 1 );
	Note( note_C , 2 );
	Note( note_D , 2 );

	Note( 0 , 2 );      //人们都幻想着你
	Note( note_E , 2 );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );

	Note( 0 , 2 );      //幻想你依偎他怀里
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_C , 6 );

//	Note( 0 , 4 );

	Note( 0 , 2 );      //一朝拥有一劳永逸
	Note( note_E , 2 );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_B , 2 );
	Note( note_A , 1 );
	Note( note_3G , 5 );

	Note( 0 , 1 );      //可是你不为谁守候
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( note_G , 4 );
	Note( note_E , 3 );
	Note( note_D , 1 );
	Note( note_C , 2 );
	Note( 0 , t );
	Note( note_C , 4 );

	Note( 0 , 1 );
	Note( note_C , 2 );      //不承诺永久
	Note( 0 , t );
	Note( note_C , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_A , 6 );

	Note( 0 , 2 );          //不轻易停留
	Note( note_A , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_C , 2 );
	Note( note_D , 10 );

	Note( 0 , 4 );
	Note( note_E , 4 );      //我知道只有不断出发
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //才能够紧随你纵情的步伐
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 5 );
	Note( note_G , 1 );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( 0 , t );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_D , 2 );
	Note( 0 , 0.1 );
	Note( note_D , 8 );

	Note( note_E , 4 );     //就算是海角至天涯
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( 0 , 0.5 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5D , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );    //青丝变白发
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_5A , 5 );

	Note( note_G , 1 );     //只等着你回答
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );

	Note( 0 , 2 );
	Note( note_D , 2 );   //我愿意呀
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_C , 12 );

	//间奏略

	Note( 0 , 4 );
	Note( note_E , 4 );      //我从来不会计算代价
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //为了你可以纵身无底悬崖
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 5 );
	Note( note_G , 1 );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( 0 , 0.1 );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_G , 4 );
	Note( note_D , 8 );

	Note( note_E , 4 );     //像条狗更像一个笑话
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //也许我很傻但我不会怕
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_5A , 6 );
	Note( 0 , t );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );

  Note( note_E , 4 );      //我知道只有不断出发
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //才能够紧随你纵情的步伐
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 5 );
	Note( note_G , 1 );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( 0 , 0.1 );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_G , 4 );
//	Note( note_D , 2 );
//	Note( 0 , 0.1 );
	Note( note_D , 8 );

	Note( note_E , 4 );     //就算是海角至天涯
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( 0 , 1 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5D , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );    //青丝变白发
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_5A , 5 );

	Note( note_G , 1 );     //只等着你回答
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );

	Note( 0 , 2 );
	Note( note_G , 2 );   //我愿意呀
	Note( note_5C , 2 );
	Note( note_5B , 1 );
	Note( note_5C , 12 );

	//尾
	Note( 0 , 4 );
	Note( note_E , 4 );
	Note( note_D , 4 );
	Note( note_C , 4 );
	Note( note_G , 4 );
	Note( note_C , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( note_F , 4 );

	Note( note_E , 4 );
	Note( note_D , 4 );
	Note( note_C , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );
	Note( note_E , 4 );
	Note( note_D , 4 );
	Note( note_C , 4 );
	Note( note_G , 4 );

	Note( note_E , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( note_F , 4 );
	Note( note_E , 4 );
	Note( note_D , 4 );

	Note( note_E , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );

	Note( note_E , 4 );
	Note( note_D , 4 );
	Note( note_C , 4 );
	Note( note_G , 4 );
	Note( note_C , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( note_F , 4 );
	Note( note_E , 4 );
	Note( note_D , 4 );
}

app_key *mu_key = NULL;

void app_botton_task(void *argument){
	while(!app_sys_ready())
		osDelay(10);

	osDelay(100);

	mu_key = get_key_s();

	for(;;){
		if(mu_key->k_state[3]){
			gala_you();
		}
		osDelay(1);
	}
}

