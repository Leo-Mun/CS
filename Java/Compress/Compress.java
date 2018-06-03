package kr.cs.kookmin.opensouce;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.zip.Adler32;
import java.util.zip.CheckedOutputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

public class Compress {
	public Compress() {};
	
	final String SLASH = "/";
	final int BUFFER = 2048;

	// zipName : 압축하여 생겨날 파일의 이름과 경로
	// target : 압축시킬 폴더
	public void compress(String zipName, String target) {
		BufferedInputStream origin = null;
		ZipOutputStream zout = null;
		
		try {
			zout = new ZipOutputStream (new BufferedOutputStream(new CheckedOutputStream(new FileOutputStream(zipName), new Adler32())));
			
			File topFile = new File(target);
			File[] subFiles = topFile.listFiles();
			
			for (int i = 0; i < subFiles.length; i++) {
				compressSelectedPath(origin, zout, subFiles[i], topFile.getName() + SLASH);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (zout != null) {
					zout.close();
				}
			} catch (IOException e) {}
		}
	}

	private void compressSelectedPath(BufferedInputStream origin, ZipOutputStream zout, File file, String parentPath) {
		if (file.isDirectory()) {
			File[] files = file.listFiles();
			if (files.length != 0) { // 폴더이고 파일을 가지고 있는 경우 압축한다.
				for (int i = 0; i < files.length; i++) {
					compressSelectedPath(origin, zout, files[i], parentPath + file.getName() + SLASH);
				}
			} else {
				// 폴더이지만 파일을 가지고 있진 않은 경우 폴더 자체만 압축한다.
				try {
					ZipEntry entry = new ZipEntry(parentPath + file.getName() + SLASH);
					zout.putNextEntry(entry);
				} catch (IOException e) {
				} finally {
					try {
						if (origin != null)
							origin.close(); 
					} catch (IOException e) {}
				}
			}
		} else {
			// 파일은 경우 압축
			// 원하는 만큼의 상위경로를 포함시켜 압축해줘야함 >> parentPath
			try {
				byte data[] = new byte[BUFFER];
				
				origin = new BufferedInputStream(new FileInputStream(file), BUFFER);
				ZipEntry entry = new ZipEntry(parentPath + file.getName());
				zout.putNextEntry(entry);
				
				int count;
				while ((count = origin.read(data, 0, BUFFER)) != -1) {
					zout.write(data,  0,  count);
				}
			} catch (IOException e) {
			} finally {
				try {
					if (origin != null) {
						origin.close();
					}
				} catch (IOException e) {}
			}
		}
	}

	
}
